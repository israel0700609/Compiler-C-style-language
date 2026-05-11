#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../BluePrintFiles/scope.h"
#include "../../../ast/ast.h"

static const char* nodeType(Node* node);
static Node* leftChild(Node* node);
static Node* rightChild(Node* node);
static Node* paramIdentifier(Node* paramNode);
static Node* paramType(Node* paramNode);
static void addSymbolForName(Scope* scope, const char* name, SymKind kind, TypeInfo typeInfo, int lineno);

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

        addSymbolForName(currentScope, idNode->value, SYM_PARAM, typeInfoFromNode(typeNode),listNode->lineno);
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

        addSymbolForName(currentScope, idNode->value, SYM_VAR, typeInfoFromNode(typeNode),listNode->lineno);
    }
}
