#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../BluePrintFiles/scope.h"
#include "../../../ast/ast.h"

int errorOccurred = 0;

static void semanticError(const char* message, const char* name) {
    if (name) {
        printf(message, name);
    } else {
        printf("%s", message);
    }
    printf("\n");
    errorOccurred = 1;
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
