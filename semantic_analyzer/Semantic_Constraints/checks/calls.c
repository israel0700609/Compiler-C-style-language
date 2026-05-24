#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../BluePrintFiles/scope.h"
#include "../../../ast/ast.h"
static void checkNodeSemantics(Node* node, Scope* currentScope);
int foundMainProcedure = 0;
static const char* nodeType(Node* node);
static Node* leftChild(Node* node);
static Node* rightChild(Node* node);
static int checkSignature(Scope* scope, Node* callNode, Symbol* symTarget, const char** errorMessage);
static void semanticError(const char* message, const char* name, int lineno);
TypeInfo typeInfoFromNode(Node* node);


static void checkCallTarget(Node* callNode, Scope* currentScope, const char* defaultErrorMessage) {
    Node* idNode = leftChild(callNode);
    if (!idNode || strcmp(nodeType(idNode), "IDENTIFIER") != 0 || !idNode->value) {
        return;
    }

    Symbol* symFunc = getSymbol(currentScope, idNode->value, SYM_FUNC);
    Symbol* symProc = getSymbol(currentScope, idNode->value, SYM_PROC);

    Symbol* targetSym = symFunc ? symFunc : symProc;

    if (targetSym == NULL) {
        semanticError(defaultErrorMessage, idNode->value, callNode->lineno);
        return; 
    }

    const char* errorMessage = NULL; 

    if (checkSignature(currentScope, callNode, targetSym, &errorMessage) != 0) {
        semanticError(errorMessage, NULL, callNode->lineno); 
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
            semanticError("Semantic Error: 'Main' cannot be declared more than once.", NULL, node->lineno);
        }

        if (strcmp(nodeType(node), "FUNCTION") == 0) {
            semanticError("Semantic Error: 'Main' must be a procedure, not a function.", NULL, node->lineno);
        }

        if (paramList != NULL) {
            semanticError("Semantic Error: Procedure 'Main' cannot take arguments.", NULL, node->lineno);
        }

        foundMainProcedure = 1;
    }
    TypeInfo retInfo = typeInfoFromNode(returnType);

    if (strcmp(nodeType(node), "FUNCTION") == 0 && retInfo.base == VAL_STRING) {
        semanticError("Semantic Error: Return type cannot be string in function '%s'.", nameNode->value,node->lineno);
    }
    SymKind funcKind = strcmp(nodeType(node), "FUNCTION") == 0 ? SYM_FUNC : SYM_PROC;
    addSymbolForName(currentScope, nameNode->value, funcKind, retInfo, node->lineno);

    Symbol* funcSym = getSymbol(currentScope, nameNode->value, funcKind);
    if (funcSym) {
        int paramCount = 0;
        for (Node* listNode = paramList; listNode != NULL; listNode = rightChild(listNode)) {
            if (strcmp(nodeType(listNode), "PARAM_LIST") != 0) continue;
            Node* paramNode = leftChild(listNode);
            if (!paramNode || strcmp(nodeType(paramNode), "PARAM") != 0) continue;
            Node* idNode = paramIdentifier(paramNode);
            Node* typeNode = paramType(paramNode);
            if (!idNode || !idNode->value) continue;
            addParam(&funcSym->details.func.params, idNode->value, typeInfoFromNode(typeNode));
            paramCount++;
        }
        funcSym->details.func.count = paramCount;
    }

    Scope* functionScope = enterScope(currentScope);
    checkParamList(paramList, functionScope);

    if (bodyNode) {
        checkNodeSemantics(bodyNode, functionScope);
    }

    exitScope(functionScope);
}
