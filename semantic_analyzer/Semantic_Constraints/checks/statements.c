#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../BluePrintFiles/scope.h"
#include "../../../ast/ast.h"

static void checkIdentifierUsage(Node* node, Scope* currentScope) {
    if (!node || !node->value) {
        return;
    }

    if (getVar(currentScope, node->value) == NULL) {
        semanticError("Semantic Error: Variable '%s' is used before it is defined.", node->value,node->lineno);
    }
}


static void checkValidReturnType(Node* node, Scope* scope) {
    Node* expr = node->left; 
    Symbol* func = getLastReturn(scope);

    if (!func) {
        semanticError("Semantic Error: 'return' statement used outside of any function.", NULL, node->lineno);
        return; 
    }

    if (func->kind == SYM_FUNC && func->type.base == VAL_STRING) {
        semanticError("Semantic Error: Function '%s' cannot return a string.", func->name, node->lineno);
    }

    if (func->kind == SYM_PROC) {
        if (expr != NULL) 
            semanticError("Semantic Error: Procedure '%s' cannot return a value.", func->name, node->lineno);
        return; 
    }

    TypeInfo exprType = getExprType(scope, expr);
    if (!matchTypes(exprType, func->type)) {
        if (exprType.base == VAL_NULL && func->type.is_ptr) 
            return;
        
        semanticError("Semantic Error: Mismatch in function '%s' return type.", func->name, node->lineno);
    }
}


static void checkBoolCondition(Node* node, Scope* scope){
    Node* expr = leftChild(node);
    if(expr == NULL){
        semanticError("Semantic Error: must define condition.", NULL, node->lineno); 
    }
    
    TypeInfo conditionType = getExprType(scope, expr);
    
    if(conditionType.base != VAL_BOOL && conditionType.base != VAL_UNKNOWN){
        semanticError("Semantic Error: condition must be of type bool.", NULL, node->lineno);
    }
}

static void checkForBoolCondition(Node* node, Scope* scope){
    Node* header = leftChild(node);

    if(header == NULL){
        semanticError("Semantic Error: Missing for header.",NULL, node->lineno);
    }
    
    Node* cond_update = rightChild(header);
    
    if(cond_update == NULL){
        semanticError("Semantic Error: Missing for loop condition update.",NULL, node->lineno);
    }

    Node* expr = leftChild(cond_update);
    
    if(expr == NULL){
        semanticError("Semantic Error: Missing for loop condition expression.",NULL, node->lineno);
    }
    
    TypeInfo conditionType = getExprType(scope,expr);
    if(conditionType.base != VAL_BOOL && conditionType.base != VAL_UNKNOWN){
        semanticError("Semantic Error: condition must be of type bool.", NULL, node->lineno);
    }
}


static void checkStringId(Node* node, Scope* scope){
    Node* idNode = leftChild(node);

    if(idNode == NULL){
        semanticError("Semantic Error: Missing identifier.", NULL, node->lineno);
    }
    
    Symbol* sym = getVar(scope, idNode->value);
    if(sym == NULL){
        semanticError("Semantic Error: Variable '%s' is used but never declared.", idNode->value, node->lineno);
    }

    TypeInfo type = sym->type;
    if(type.base != VAL_STRING){
        semanticError("Semantic Error: Cannot access non-string type variable '%s'.", idNode->value, node->lineno);
    }
}

static void checkValidIndexType(Node* node, Scope* scope){
    Node* indexExpr = rightChild(node);
    
    checkNodeSemantics(indexExpr, scope);
        
    TypeInfo indexType = getExprType(scope, indexExpr);

    if (indexType.base != VAL_INT && indexType.base != VAL_UNKNOWN) {
        semanticError("Semantic Error: String index must be of type int.", NULL, node->lineno);
    }
}

static void checkValidString(Node* node, Scope* scope){
    Node* expr = leftChild(node);
    checkNodeSemantics(expr,scope);

    TypeInfo sizeType = getExprType(scope,expr);

    if(sizeType.base != VAL_INT && sizeType.base != VAL_UNKNOWN){
        semanticError("Semantic Error: String size must be of type int.",NULL, node->lineno);
    }
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
            semanticError("Semantic Error: 'null' can only be assigned to int*, real*, or char* pointers.", NULL, node->lineno);        
        }
        return; 
    }


    if (!matchTypes(lhsType, rhsType)) {
        semanticError("Semantic Error: Type mismatch in assignment.", NULL, node->lineno);
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
        if(strcmp(nodeType(typeNode),"STRING_ARRAY_TYPE") == 0){
            checkValidString(typeNode, currentScope);
        }
        if (idNode && strcmp(nodeType(idNode), "IDENTIFIER") == 0 && idNode->value) {
            addSymbolForName(currentScope, idNode->value, SYM_VAR, typeInfoFromNode(typeNode), node->lineno);
        }
        return;
    }

    if (strcmp(nodeType(node), "PARAM") == 0) {
        Node* idNode = leftChild(node);
        Node* typeNode = rightChild(node);
        if(strcmp(nodeType(typeNode),"STRING_ARRAY_TYPE") == 0){
            checkValidString(typeNode, currentScope);
        }
        if (idNode && strcmp(nodeType(idNode), "IDENTIFIER") == 0 && idNode->value) {
            addSymbolForName(currentScope, idNode->value, SYM_PARAM, typeInfoFromNode(typeNode), node->lineno);
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
        return;
    }

    if(strcmp(nodeType(node),"IF_ELSE_STTMNT") == 0){
        checkBoolCondition(node,currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
        return;
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

    if (strcmp(nodeType(node), "STRLEN") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkStrlenOp(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "NOT") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkNotOp(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "NEG") == 0 || strcmp(nodeType(node), "POS") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkUnaryArithOp(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "DEREF") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkDereferenceOp(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "ADDR_OF") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkAddressOfOp(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "ADD") == 0 || strcmp(nodeType(node), "SUB") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
        checkPointerArithmetic(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "MUL") == 0 || strcmp(nodeType(node), "DIV") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
        checkArithmeticOp(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "AND") == 0 || strcmp(nodeType(node), "OR") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
        checkLogicalOp(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "GT") == 0 || strcmp(nodeType(node), "LT")  == 0 ||
        strcmp(nodeType(node), "GTE") == 0 || strcmp(nodeType(node), "LTE") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
        checkRelationalOp(currentScope, node);
        return;
    }
    if (strcmp(nodeType(node), "EQ") == 0 || strcmp(nodeType(node), "NEQ") == 0) {
        checkNodeSemantics(leftChild(node), currentScope);
        checkNodeSemantics(rightChild(node), currentScope);
        checkEqualityOp(currentScope, node);
        return;
    }

    checkNodeSemantics(leftChild(node), currentScope);
    checkNodeSemantics(rightChild(node), currentScope);
}
