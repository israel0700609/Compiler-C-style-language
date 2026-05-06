#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scope.h"
#include "ast.h"
#include "checks/utils.c"

int foundMainProcedure = 0;
static const char* nodeType(Node* node);
static Node* leftChild(Node* node);
static Node* rightChild(Node* node);
static int checkSignature(Scope* scope, Node* callNode, Symbol* symTarget, const char** errorMessage);
static void semanticError(const char* message, const char* name);

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
