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

static void checkNodeSemantics(Node* node, Scope* currentScope);

static void checkParamList(Node* paramList, Scope* currentScope) {
    for (Node* listNode = paramList; listNode != NULL; listNode = rightChild(listNode)) {
        if (strcmp(nodeType(listNode), "PARAM_LIST") != 0) {
            continue;
        }

        Node* paramNode = leftChild(listNode);
        if (paramNode) {
            checkNodeSemantics(paramNode, currentScope);
        }
    }
}

static void checkVarList(Node* varList, Scope* currentScope) {
    for (Node* listNode = varList; listNode != NULL; listNode = rightChild(listNode)) {
        if (strcmp(nodeType(listNode), "VAR_LIST") != 0) {
            continue;
        }

        Node* varNode = leftChild(listNode);
        if (varNode) {
            checkNodeSemantics(varNode, currentScope);
        }
    }
}
