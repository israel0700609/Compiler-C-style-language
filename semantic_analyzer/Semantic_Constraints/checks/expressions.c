#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../BluePrintFiles/scope.h"
#include "../../../ast/ast.h"

static void semanticError(const char* message, const char* name);
TypeInfo getExprType(Scope* scope, Node* node);

void checkArithmeticOp(Scope* scope, Node* node) {
    TypeInfo left  = getExprType(scope, node->left);
    TypeInfo right = getExprType(scope, node->right);
    if (left.base == VAL_UNKNOWN || right.base == VAL_UNKNOWN) return;
    if (left.is_ptr || right.is_ptr)
        semanticError("Semantic Error: '*'/'/' operators cannot be applied to pointers.", NULL);
    if ((left.base != VAL_INT && left.base != VAL_REAL) ||
        (right.base != VAL_INT && right.base != VAL_REAL))
        semanticError("Semantic Error: '*'/'/' operators require int or real operands.", NULL);
}

void checkLogicalOp(Scope* scope, Node* node) {
    TypeInfo left  = getExprType(scope, node->left);
    TypeInfo right = getExprType(scope, node->right);
    if (left.base == VAL_UNKNOWN || right.base == VAL_UNKNOWN) return;
    if (left.base != VAL_BOOL || right.base != VAL_BOOL)
        semanticError("Semantic Error: '&&'/'||' operators require bool operands.", NULL);
}

void checkRelationalOp(Scope* scope, Node* node) {
    TypeInfo left  = getExprType(scope, node->left);
    TypeInfo right = getExprType(scope, node->right);
    if (left.base == VAL_UNKNOWN || right.base == VAL_UNKNOWN) return;
    if ((left.base != VAL_INT && left.base != VAL_REAL) ||
        (right.base != VAL_INT && right.base != VAL_REAL))
        semanticError("Semantic Error: Comparison operators '<','<=','>','>=' require int or real operands.", NULL);
}

void checkEqualityOp(Scope* scope, Node* node) {
    TypeInfo left  = getExprType(scope, node->left);
    TypeInfo right = getExprType(scope, node->right);
    if (left.base == VAL_UNKNOWN || right.base == VAL_UNKNOWN) return;
    if ((left.base == VAL_NULL && right.is_ptr) || (right.base == VAL_NULL && left.is_ptr))
        return;
    if (!matchTypes(left, right))
        semanticError("Semantic Error: '=='/'!=' requires operands of the same type.", NULL);
    if (left.base == VAL_STRING)
        semanticError("Semantic Error: Cannot compare string types with '=='/'!='.", NULL);
}

void checkPointerArithmetic(Scope* scope, Node* node) {
    TypeInfo left  = getExprType(scope, node->left);
    TypeInfo right = getExprType(scope, node->right);
    if (left.base == VAL_UNKNOWN || right.base == VAL_UNKNOWN) return;

    int isSub = (strcmp(node->type, "SUB") == 0);

    if (left.is_ptr) {
        if (left.base != VAL_CHAR)
            semanticError("Semantic Error: Pointer arithmetic is only supported for char pointers.", NULL);
        if (right.base != VAL_INT || right.is_ptr)
            semanticError("Semantic Error: Can only add or subtract int from a char pointer.", NULL);
        return;
    }

    if (right.is_ptr && !isSub) {
        if (right.base != VAL_CHAR)
            semanticError("Semantic Error: Pointer arithmetic is only supported for char pointers.", NULL);
        if (left.base != VAL_INT || left.is_ptr)
            semanticError("Semantic Error: Can only add or subtract int from a char pointer.", NULL);
        return;
    }

    if ((left.base != VAL_INT && left.base != VAL_REAL) ||
        (right.base != VAL_INT && right.base != VAL_REAL))
        semanticError("Semantic Error: '+'/'-' operators require int or real operands.", NULL);
}

void checkAddressOfOp(Scope* scope, Node* node) {
    Node* inner = node->left;
    if (!inner) return;
    TypeInfo innerType = getExprType(scope, inner);
    if (innerType.base == VAL_UNKNOWN) return;

    if (strcmp(inner->type, "ARRAY_ACCESS") == 0) return;
    if (strcmp(inner->type, "IDENTIFIER") == 0 && !innerType.is_ptr) {
        if (innerType.base == VAL_INT || innerType.base == VAL_REAL || innerType.base == VAL_CHAR)
            return;
    }
    semanticError("Semantic Error: '&' operator can only be applied to int, real, char variables or string elements.", NULL);
}

void checkDereferenceOp(Scope* scope, Node* node) {
    TypeInfo innerType = getExprType(scope, node->left);
    if (innerType.base == VAL_UNKNOWN) return;
    if (!innerType.is_ptr)
        semanticError("Semantic Error: Dereference operator '^' can only be applied to pointers.", NULL);
}

void checkStrlenOp(Scope* scope, Node* node) {
    TypeInfo innerType = getExprType(scope, node->left);
    if (innerType.base != VAL_STRING && innerType.base != VAL_UNKNOWN)
        semanticError("Semantic Error: '|...|' operator can only be applied to strings.", NULL);
}

void checkNotOp(Scope* scope, Node* node) {
    TypeInfo innerType = getExprType(scope, node->left);
    if (innerType.base != VAL_BOOL && innerType.base != VAL_UNKNOWN)
        semanticError("Semantic Error: '!' operator can only be applied to bool.", NULL);
}

void checkUnaryArithOp(Scope* scope, Node* node) {
    TypeInfo innerType = getExprType(scope, node->left);
    if (innerType.base != VAL_INT && innerType.base != VAL_REAL && innerType.base != VAL_UNKNOWN)
        semanticError("Semantic Error: Unary '+'/'-' can only be applied to int or real.", NULL);
}
