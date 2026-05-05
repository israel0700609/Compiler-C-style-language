#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scope.h"
#include "ast.h"

static int foundMainProcedure = 0;

static void semanticError(const char* message, const char* name) {
    if (name) {
        printf(message, name);
    } else {
        printf("%s", message);
    }
    printf("\n");
    exit(1);
}

static const char* nodeType(Node* node) {
    return (node && node->type) ? node->type : "";
}

static Node* leftChild(Node* node) {
    return node ? node->left : NULL;
}

static Node* rightChild(Node* node) {
    return node ? node->right : NULL;
}

static TypeInfo typeInfoFromNode(Node* typeNode) {
    TypeInfo info = {VAL_UNKNOWN, 0};

    if (!typeNode || !typeNode->type) {
        return info;
    }

    if (strcmp(typeNode->type, "TYPE") == 0) {
        return parseType(typeNode->value);
    }

    if (strcmp(typeNode->type, "STRING_ARRAY_TYPE") == 0) {
        info.base = VAL_STRING;
        info.is_ptr = 0;
        return info;
    }

    return parseType(typeNode->value);
}

static Node* paramIdentifier(Node* paramNode) {
    return leftChild(paramNode);
}

static Node* paramType(Node* paramNode) {
    return rightChild(paramNode);
}

static void addSymbolForName(Scope* scope, const char* name, SymKind kind, TypeInfo typeInfo) {
    if (isLocal(scope, (char*)name)) {
        if (kind == SYM_FUNC || kind == SYM_PROC) {
            semanticError("Semantic Error: Function or Procedure '%s' is already defined.", name);
        } else {
            semanticError("Semantic Error: Variable '%s' is already defined in the current scope.", name);
        }
    }

    Symbol* symbol = (Symbol*)calloc(1, sizeof(Symbol));
    if (!symbol) {
        fprintf(stderr, "Fatal: Memory allocation failed while creating a symbol.\n");
        exit(1);
    }

    symbol->name = strdup(name);
    if (!symbol->name) {
        fprintf(stderr, "Fatal: Memory allocation failed while copying a symbol name.\n");
        free(symbol);
        exit(1);
    }

    symbol->kind = kind;
    symbol->type = typeInfo;
    symbol->details.func.params = NULL;
    symbol->details.func.count = 0;
    symbol->next = NULL;
    addSymbol(scope, symbol);
}

static void checkNodeSemantics(Node* node, Scope* currentScope);

static void checkParamList(Node* paramList, Scope* currentScope) {
    for (Node* listNode = paramList; listNode != NULL; listNode = rightChild(listNode)) {
        if (strcmp(nodeType(listNode), "PARAM_LIST") != 0) {
            continue;
        }

        Node* paramNode = leftChild(listNode);
        if (!paramNode || strcmp(nodeType(paramNode), "PARAM") != 0) {
            continue;
        }

        Node* idNode = paramIdentifier(paramNode);
        Node* typeNode = paramType(paramNode);

        if (!idNode || strcmp(nodeType(idNode), "IDENTIFIER") != 0 || !idNode->value) {
            continue;
        }

        addSymbolForName(currentScope, idNode->value, SYM_PARAM, typeInfoFromNode(typeNode));
    }
}

static void checkVarList(Node* varList, Scope* currentScope) {
    for (Node* listNode = varList; listNode != NULL; listNode = rightChild(listNode)) {
        if (strcmp(nodeType(listNode), "VAR_LIST") != 0) {
            continue;
        }

        Node* varNode = leftChild(listNode);
        if (!varNode || strcmp(nodeType(varNode), "VAR_DECL") != 0) {
            continue;
        }

        Node* idNode = leftChild(varNode);
        Node* typeNode = rightChild(varNode);

        if (!idNode || strcmp(nodeType(idNode), "IDENTIFIER") != 0 || !idNode->value) {
            continue;
        }

        addSymbolForName(currentScope, idNode->value, SYM_VAR, typeInfoFromNode(typeNode));
    }
}

static Param* parseArgs(Scope* scope, Node* arguments, int* count) {
    int i = 0;
    Param* args = NULL; 

    while (arguments != NULL) {
        if (strcmp(nodeType(arguments), "ARGUMENTS_LIST") != 0) {
            break; 
        }
        
        i++;
        Node* expr = leftChild(arguments);
        TypeInfo currType = getExprType(scope, expr);
        
        addParam(&args, "arg", currType); 
        
        arguments = rightChild(arguments);
    }
    
    *count = i;
    return args;
}


static int checkSignature(Scope* scope, Node* callNode, Symbol* symTarget, const char** errorMessage) {
    if (!symTarget) return -1;

    Node* argsnode = rightChild(callNode); 
    int count = 0;
    
    Param* args = parseArgs(scope, argsnode, &count); 
    
    Param* params = symTarget->details.func.params; 
    int required = symTarget->details.func.count;
    
    int result = 0; 

    if (required != count) {
        *errorMessage = "Semantic Error: Mismatch in the number of arguments.";
        result = -1;
    } else {
        Param* currParam = params;
        Param* currArg = args;
        
        while (currParam != NULL && currArg != NULL) {
            if (!matchTypes(currParam->type, currArg->type)) {
                *errorMessage = "Semantic Error: Mismatch in the type of arguments.";
                result = 1;
                break;
            }
            currParam = currParam->next;
            currArg = currArg->next;
        }
    }

    freeParams(args); 

    return result;
}

static void checkCallTarget(Node* callNode, Scope* currentScope, const char* defaultErrorMessage) {
    Node* idNode = leftChild(callNode);
    if (!idNode || strcmp(nodeType(idNode), "IDENTIFIER") != 0 || !idNode->value) {
        return;
    }

    Symbol* symFunc = getSymbol(currentScope, idNode->value, SYM_FUNC);
    Symbol* symProc = getSymbol(currentScope, idNode->value, SYM_PROC);

    Symbol* targetSym = symFunc ? symFunc : symProc;

    if (targetSym == NULL) {
        semanticError(defaultErrorMessage, idNode->value);
        return; 
    }

    const char* errorMessage = NULL; 

    if (checkSignature(currentScope, callNode, targetSym, &errorMessage) != 0) {
        semanticError(errorMessage, NULL); 
    }
}


static void checkFunctionOrProcedure(Node* node, Scope* currentScope) {
    Node* nameNode = leftChild(node);
    Node* bodyNode = rightChild(node);
    Node* paramList = nameNode ? leftChild(nameNode) : NULL;
    Node* returnType = nameNode ? rightChild(nameNode) : NULL;

    if (!nameNode || strcmp(nodeType(nameNode), "IDENTIFIER") != 0 || !nameNode->value) {
        return;
    }

    if (strcmp(nameNode->value, "Main") == 0) {
        if (foundMainProcedure) {
            semanticError("Semantic Error: 'Main' cannot be declared more than once.", NULL);
        }

        if (strcmp(nodeType(node), "FUNCTION") == 0) {
            semanticError("Semantic Error: 'Main' must be a procedure, not a function.", NULL);
        }

        if (paramList != NULL) {
            semanticError("Semantic Error: Procedure 'Main' cannot take arguments.", NULL);
        }

        foundMainProcedure = 1;
    }
    TypeInfo retInfo = typeInfoFromNode(returnType);

    if (strcmp(nodeType(node), "FUNCTION") == 0 && retInfo.base == VAL_STRING) {
        semanticError("Semantic Error: Return type cannot be string in function '%s'.", nameNode->value);
    }
    addSymbolForName(currentScope, nameNode->value,
                     strcmp(nodeType(node), "FUNCTION") == 0 ? SYM_FUNC : SYM_PROC,
                     retInfo);

    Scope* functionScope = enterScope(currentScope);
    checkParamList(paramList, functionScope);

    if (bodyNode) {
        checkNodeSemantics(bodyNode, functionScope);
    }

    exitScope(functionScope);
}

static void checkIdentifierUsage(Node* node, Scope* currentScope) {
    if (!node || !node->value) {
        return;
    }

    if (getVar(currentScope, node->value) == NULL) {
        semanticError("Semantic Error: Variable '%s' is used before it is defined.", node->value);
    }
}


static void checkValidReturnType(Node* node, Scope* scope) {
    Node* expr = node->left; 
    Symbol* func = getLastReturn(scope);

    if (!func) {
        semanticError("Semantic Error: 'return' statement used outside of any function.", NULL);
        return; 
    }

    if (func->kind == SYM_FUNC && func->type.base == VAL_STRING) {
        semanticError("Semantic Error: Function '%s' cannot return a string.", func->name);
    }

    if (func->kind == SYM_PROC) {
        if (expr != NULL) 
            semanticError("Semantic Error: Procedure '%s' cannot return a value.", func->name);
        return; 
    }

    TypeInfo exprType = getExprType(scope, expr);
    if (!matchTypes(exprType, func->type)) {
        if (exprType.base == VAL_NULL && func->type.is_ptr) 
            return;
        
        semanticError("Semantic Error: Mismatch in function '%s' return type.", func->name);
    }
}


static void checkBoolCondition(Node* node, Scope* scope){
    Node* expr = leftChild(node);
    if(expr == NULL){
        semanticError("Semantic Error: must define condition.", NULL); 
    }
    
    TypeInfo conditionType = getExprType(scope, expr);
    
    if(conditionType.base != VAL_BOOL && conditionType.base != VAL_UNKNOWN){
        semanticError("Semantic Error: condition must be of type bool.", NULL);
    }
}

static void checkForBoolCondition(Node* node, Scope* scope){
    Node* header = leftChild(node);

    if(header == NULL){
        semanticError("Semantic Error: Missing for header.",NULL);
    }
    
    Node* cond_update = rightChild(header);
    
    if(cond_update == NULL){
        semanticError("Semantic Error: Missing for loop condition update.",NULL);
    }

    Node* expr = leftChild(cond_update);
    
    if(expr == NULL){
        semanticError("Semantic Error: Missing for loop condition expression.",NULL);
    }
    
    TypeInfo conditionType = getExprType(scope,expr);
    if(conditionType.base != VAL_BOOL && conditionType.base != VAL_UNKNOWN){
        semanticError("Semantic Error: condition must be of type bool.", NULL);
    }
}


static void checkStringId(Node* node, Scope* scope){
    Node* idNode = leftChild(node);

    if(idNode == NULL){
        semanticError("Semantic Error: Missing identifier.", NULL);
    }
    
    Symbol* sym = getVar(scope, idNode->value);
    if(sym == NULL){
        semanticError("Semantic Error: Variable '%s' is used but never declared.", idNode->value);
    }

    TypeInfo type = sym->type;
    if(type.base != VAL_STRING){
        semanticError("Semantic Error: Cannot access non-string type variable '%s'.", idNode->value);
    }
}

static void checkValidIndexType(Node* node, Scope* scope){
    Node* indexExpr = rightChild(node);
    
    checkNodeSemantics(indexExpr, scope);
        
    TypeInfo indexType = getExprType(scope, indexExpr);

    if (indexType.base != VAL_INT && indexType.base != VAL_UNKNOWN) {
        semanticError("Semantic Error: String index must be of type int.", NULL);
    }
}

static TypeInfo getLhsType(Scope* scope, Node* lhsNode) {
    TypeInfo unknownType = {VAL_UNKNOWN, 0};
    if (!lhsNode) return unknownType;

    const char* typeStr = nodeType(lhsNode);

    if (strcmp(typeStr, "IDENTIFIER") == 0) {
        Symbol* sym = getVar(scope, lhsNode->value);
        if (sym) {
            return sym->type;
        }
        return unknownType; 
    }

    if (strcmp(typeStr, "ARRAY_ACCESS") == 0) {
        TypeInfo charType = {VAL_CHAR, 0};
        return charType;
    }

    if (strcmp(typeStr, "DEREF") == 0) {
        Node* innerNode = leftChild(lhsNode);
    
        TypeInfo innerType = getExprType(scope, innerNode);
        
        if (innerType.base == VAL_UNKNOWN) {
            return unknownType;
        }
        
        if (innerType.is_ptr == 1) {
            innerType.is_ptr = 0;
            return innerType;
        } else {
            semanticError("Semantic Error: Cannot dereference a non-pointer.", NULL);
            return unknownType;
        }
    }

    return unknownType;
}


static void checkAssignment(Node* node, Scope* scope) {
    Node* lhsNode = leftChild(node);
    Node* rhsNode = rightChild(node);

    checkNodeSemantics(lhsNode, scope);
    checkNodeSemantics(rhsNode, scope);

    TypeInfo lhsType = getLhsType(scope, lhsNode);
    TypeInfo rhsType = getExprType(scope, rhsNode);

    if (lhsType.base == VAL_UNKNOWN || rhsType.base == VAL_UNKNOWN) {
        return;
    }

    if (rhsType.base == VAL_NULL) {
        if (lhsType.is_ptr == 0 || (lhsType.base != VAL_INT && lhsType.base != VAL_REAL && lhsType.base != VAL_CHAR)) {
            semanticError("Semantic Error: 'null' can only be assigned to int*, real*, or char* pointers.", NULL);        
        }
        return; 
    }


    if (!matchTypes(lhsType, rhsType)) {
        semanticError("Semantic Error: Type mismatch in assignment.", NULL);
    }
}


static void checkNodeSemantics(Node* node, Scope* currentScope) {
    if (!node) {
        return;
    }
    if (strcmp(nodeType(node), "BLOCK") == 0) {
        Scope* blockScope = enterScope(currentScope);
        
        checkNodeSemantics(leftChild(node), blockScope);
        
        exitScope(blockScope);
        return;
    }
    
    if (strcmp(nodeType(node), "FUNCTION") == 0 || strcmp(nodeType(node), "PROC") == 0) {
        checkFunctionOrProcedure(node, currentScope);
        return;
    }

    if (strcmp(nodeType(node), "VAR_LIST") == 0) {
        checkVarList(node, currentScope);
        return;
    }

    if (strcmp(nodeType(node), "PARAM_LIST") == 0) {
        checkParamList(node, currentScope);
        return;
    }

    if (strcmp(nodeType(node), "VAR_DECL") == 0) {
        Node* idNode = leftChild(node);
        Node* typeNode = rightChild(node);

        if (idNode && strcmp(nodeType(idNode), "IDENTIFIER") == 0 && idNode->value) {
            addSymbolForName(currentScope, idNode->value, SYM_VAR, typeInfoFromNode(typeNode));
        }
        return;
    }

    if (strcmp(nodeType(node), "PARAM") == 0) {
        Node* idNode = leftChild(node);
        Node* typeNode = rightChild(node);

        if (idNode && strcmp(nodeType(idNode), "IDENTIFIER") == 0 && idNode->value) {
            addSymbolForName(currentScope, idNode->value, SYM_PARAM, typeInfoFromNode(typeNode));
        }
        return;
    }

    if (strcmp(nodeType(node), "CALL_STTMNT") == 0) {
        checkCallTarget(node, currentScope, "Semantic Error: Function/Procedure '%s' is called before it is defined.");
        checkNodeSemantics(rightChild(node), currentScope);
        return;
    }

    if (strcmp(nodeType(node), "FUNC_CALL") == 0) {
        checkCallTarget(node, currentScope, "Semantic Error: Function '%s' is called before it is defined.");
        checkNodeSemantics(rightChild(node), currentScope);
        return;
    }

    if (strcmp(nodeType(node), "IDENTIFIER") == 0) {
        checkIdentifierUsage(node, currentScope);
        return;
    }

    if(strcmp(nodeType(node),"RETURN_STTMNT") == 0){
        checkValidReturnType(node,currentScope);
        return;
    }

    if(strcmp(nodeType(node),"IF_STTMNT") == 0){
        checkBoolCondition(node,currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
    }

    if(strcmp(nodeType(node),"IF_ELSE_STTMNT") == 0){
        checkBoolCondition(node,currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
    }

    if(strcmp(nodeType(node),"WHILE_STTMNT") == 0){
        checkBoolCondition(node,currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
        return;
    }

    if(strcmp(nodeType(node),"FOR_STTMNT") == 0){
        checkForBoolCondition(node,currentScope);
        checkNodeSemantics(rightChild(node),currentScope);
        return;
    }

    if(strcmp(nodeType(node),"ARRAY_ACCESS") == 0){
        checkStringId(node,currentScope);
        checkValidIndexType(node,currentScope);
        return;
    }   

    if(strcmp(nodeType(node),"ASSIGN_STTMNT") == 0){
        checkAssignment(node,currentScope);
        return;
    }
    
    checkNodeSemantics(leftChild(node), currentScope);
    checkNodeSemantics(rightChild(node), currentScope);
}

void runSemanticChecks(Node* root) {
    Scope* globalScope = enterScope(NULL);
    foundMainProcedure = 0;

    checkNodeSemantics(root, globalScope);

    if (!foundMainProcedure) {
        printf("Semantic Error: Procedure 'Main' is missing from the program.\n");
        exit(1);
    }

    exitScope(globalScope);
}