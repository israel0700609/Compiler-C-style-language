#include "three_ac.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE* out;
    int tempCounter;
    int labelCounter;
} CodegenContext;

static const char* nodeType(Node* node) {
    return (node && node->type) ? node->type : "";
}

static Node* leftChild(Node* node) {
    return node ? node->left : NULL;
}

static Node* rightChild(Node* node) {
    return node ? node->right : NULL;
}

static char* dupString(const char* s) {
    if (!s) {
        return NULL;
    }

    size_t n = strlen(s) + 1;
    char* out = (char*)malloc(n);
    if (!out) {
        fprintf(stderr, "Fatal: out of memory while duplicating string.\n");
        exit(1);
    }
    memcpy(out, s, n);
    return out;
}

static void emit(CodegenContext* ctx, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(ctx->out, fmt, args);
    va_end(args);
}

static char* newTemp(CodegenContext* ctx) {
    char buf[32];
    snprintf(buf, sizeof(buf), "t%d", ++ctx->tempCounter);
    return dupString(buf);
}

static char* newLabel(CodegenContext* ctx) {
    char buf[32];
    snprintf(buf, sizeof(buf), "L%d", ++ctx->labelCounter);
    return dupString(buf);
}

static int isRelop(const char* t) {
    return strcmp(t, "GT") == 0 || strcmp(t, "LT") == 0 || strcmp(t, "GTE") == 0 ||
           strcmp(t, "LTE") == 0 || strcmp(t, "EQ") == 0 || strcmp(t, "NEQ") == 0;
}

static const char* mapRelop(const char* t) {
    if (strcmp(t, "GT") == 0) return ">";
    if (strcmp(t, "LT") == 0) return "<";
    if (strcmp(t, "GTE") == 0) return ">=";
    if (strcmp(t, "LTE") == 0) return "<=";
    if (strcmp(t, "EQ") == 0) return "==";
    if (strcmp(t, "NEQ") == 0) return "!=";
    return "?";
}

static const char* mapBinop(const char* t) {
    if (strcmp(t, "ADD") == 0) return "+";
    if (strcmp(t, "SUB") == 0) return "-";
    if (strcmp(t, "MUL") == 0) return "*";
    if (strcmp(t, "DIV") == 0) return "/";
    if (strcmp(t, "EQ") == 0) return "==";
    if (strcmp(t, "NEQ") == 0) return "!=";
    if (strcmp(t, "GT") == 0) return ">";
    if (strcmp(t, "LT") == 0) return "<";
    if (strcmp(t, "GTE") == 0) return ">=";
    if (strcmp(t, "LTE") == 0) return "<=";
    return "?";
}

static char* genExpr(CodegenContext* ctx, Node* expr);

static int countArgs(Node* args) {
    int count = 0;
    Node* curr = args;

    while (curr && strcmp(nodeType(curr), "ARGUMENTS_LIST") == 0) {
        count++;
        curr = rightChild(curr);
    }

    return count;
}

static void genCallArgs(CodegenContext* ctx, Node* args) {
    Node* curr = args;

    while (curr && strcmp(nodeType(curr), "ARGUMENTS_LIST") == 0) {
        Node* expr = leftChild(curr);
        char* arg = genExpr(ctx, expr);
        emit(ctx, "    PushParam %s\n", arg);
        free(arg);
        curr = rightChild(curr);
    }
}

static void genCondition(CodegenContext* ctx, Node* expr, const char* trueLabel, const char* falseLabel) {
    const char* t = nodeType(expr);

    if (strcmp(t, "OR") == 0) {
        char* mid = newLabel(ctx);
        genCondition(ctx, leftChild(expr), trueLabel, mid);
        emit(ctx, "%s:\n", mid);
        genCondition(ctx, rightChild(expr), trueLabel, falseLabel);
        free(mid);
        return;
    }

    if (strcmp(t, "AND") == 0) {
        char* mid = newLabel(ctx);
        genCondition(ctx, leftChild(expr), mid, falseLabel);
        emit(ctx, "%s:\n", mid);
        genCondition(ctx, rightChild(expr), trueLabel, falseLabel);
        free(mid);
        return;
    }

    if (strcmp(t, "NOT") == 0) {
        genCondition(ctx, leftChild(expr), falseLabel, trueLabel);
        return;
    }

    if (isRelop(t)) {
        char* lhs = genExpr(ctx, leftChild(expr));
        char* rhs = genExpr(ctx, rightChild(expr));
        emit(ctx, "    if %s %s %s Goto %s\n", lhs, mapRelop(t), rhs, trueLabel);
        emit(ctx, "    goto %s\n", falseLabel);
        free(lhs);
        free(rhs);
        return;
    }

    {
        char* v = genExpr(ctx, expr);
        emit(ctx, "    if %s != 0 Goto %s\n", v, trueLabel);
        emit(ctx, "    goto %s\n", falseLabel);
        free(v);
    }
}

static char* genBoolExprToTemp(CodegenContext* ctx, Node* expr) {
    char* out = newTemp(ctx);
    char* lTrue = newLabel(ctx);
    char* lFalse = newLabel(ctx);
    char* lEnd = newLabel(ctx);

    genCondition(ctx, expr, lTrue, lFalse);

    emit(ctx, "%s:\n", lTrue);
    emit(ctx, "    %s = 1\n", out);
    emit(ctx, "    goto %s\n", lEnd);

    emit(ctx, "%s:\n", lFalse);
    emit(ctx, "    %s = 0\n", out);

    emit(ctx, "%s:\n", lEnd);

    free(lTrue);
    free(lFalse);
    free(lEnd);

    return out;
}

static char* genExpr(CodegenContext* ctx, Node* expr) {
    const char* t = nodeType(expr);

    if (strcmp(t, "IDENTIFIER") == 0) {
        return dupString(expr->value ? expr->value : "");
    }

    if (strcmp(t, "INT_LITERAL") == 0 || strcmp(t, "REAL_LITERAL") == 0 || strcmp(t, "CHAR_LITERAL") == 0) {
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = %s\n", tmp, expr->value ? expr->value : "0");
        return tmp;
    }

    if (strcmp(t, "BOOL_LITERAL") == 0) {
        char* tmp = newTemp(ctx);
        int v = (expr->value && strcmp(expr->value, "true") == 0) ? 1 : 0;
        emit(ctx, "    %s = %d\n", tmp, v);
        return tmp;
    }

    if (strcmp(t, "STRING_LITERAL") == 0) {
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = \"%s\"\n", tmp, expr->value ? expr->value : "");
        return tmp;
    }

    if (strcmp(t, "NULL") == 0) {
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = null\n", tmp);
        return tmp;
    }

    if (strcmp(t, "ARRAY_ACCESS") == 0) {
        Node* idNode = leftChild(expr);
        Node* idxNode = rightChild(expr);
        char* idx = genExpr(ctx, idxNode);
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = %s[%s]\n", tmp, idNode && idNode->value ? idNode->value : "", idx);
        free(idx);
        return tmp;
    }

    if (strcmp(t, "FUNC_CALL") == 0) {
        Node* idNode = leftChild(expr);
        Node* args = rightChild(expr);
        int argCount = countArgs(args);

        genCallArgs(ctx, args);

        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = LCall %s\n", tmp, idNode && idNode->value ? idNode->value : "");
        emit(ctx, "    PopParams %d\n", argCount * 8);
        return tmp;
    }

    if (strcmp(t, "DEREF") == 0) {
        char* inner = genExpr(ctx, leftChild(expr));
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = ^%s\n", tmp, inner);
        free(inner);
        return tmp;
    }

    if (strcmp(t, "ADDR_OF") == 0) {
        char* inner = genExpr(ctx, leftChild(expr));
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = &%s\n", tmp, inner);
        free(inner);
        return tmp;
    }

    if (strcmp(t, "STRLEN") == 0) {
        char* inner = genExpr(ctx, leftChild(expr));
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = |%s|\n", tmp, inner);
        free(inner);
        return tmp;
    }

    if (strcmp(t, "NOT") == 0 || strcmp(t, "AND") == 0 || strcmp(t, "OR") == 0) {
        return genBoolExprToTemp(ctx, expr);
    }

    if (strcmp(t, "NEG") == 0 || strcmp(t, "POS") == 0) {
        char* inner = genExpr(ctx, leftChild(expr));
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = %s%s\n", tmp, strcmp(t, "NEG") == 0 ? "-" : "+", inner);
        free(inner);
        return tmp;
    }

    if (strcmp(t, "ADD") == 0 || strcmp(t, "SUB") == 0 || strcmp(t, "MUL") == 0 ||
        strcmp(t, "DIV") == 0 || isRelop(t)) {
        char* lhs = genExpr(ctx, leftChild(expr));
        char* rhs = genExpr(ctx, rightChild(expr));
        char* tmp = newTemp(ctx);
        emit(ctx, "    %s = %s %s %s\n", tmp, lhs, mapBinop(t), rhs);
        free(lhs);
        free(rhs);
        return tmp;
    }

    return dupString("0");
}

static void genAssign(CodegenContext* ctx, Node* node) {
    Node* lhs = leftChild(node);
    Node* rhs = rightChild(node);
    const char* lhsType = nodeType(lhs);

    char* rhsPlace = genExpr(ctx, rhs);

    if (strcmp(lhsType, "IDENTIFIER") == 0) {
        emit(ctx, "    %s = %s\n", lhs->value ? lhs->value : "", rhsPlace);
    } else if (strcmp(lhsType, "ARRAY_ACCESS") == 0) {
        Node* idNode = leftChild(lhs);
        Node* idxNode = rightChild(lhs);
        char* idx = genExpr(ctx, idxNode);
        emit(ctx, "    %s[%s] = %s\n", idNode && idNode->value ? idNode->value : "", idx, rhsPlace);
        free(idx);
    } else if (strcmp(lhsType, "DEREF") == 0) {
        char* ptr = genExpr(ctx, leftChild(lhs));
        emit(ctx, "    ^%s = %s\n", ptr, rhsPlace);
        free(ptr);
    }

    free(rhsPlace);
}

static void genStatement(CodegenContext* ctx, Node* node);

static void genNodeList(CodegenContext* ctx, Node* node) {
    if (!node) {
        return;
    }

    if (strcmp(nodeType(node), "STATEMENTS") == 0 || strcmp(nodeType(node), "DECLARATIONS") == 0) {
        genNodeList(ctx, leftChild(node));
        genNodeList(ctx, rightChild(node));
        return;
    }

    genStatement(ctx, node);
}

static void genIf(CodegenContext* ctx, Node* node) {
    Node* cond = leftChild(node);
    Node* right = rightChild(node);

    char* lTrue = newLabel(ctx);
    char* lFalse = newLabel(ctx);

    if (strcmp(nodeType(node), "IF_STTMNT") == 0) {
        Node* thenNode = right ? leftChild(right) : NULL;
        genCondition(ctx, cond, lTrue, lFalse);

        emit(ctx, "%s:\n", lTrue);
        genStatement(ctx, thenNode);

        emit(ctx, "%s:\n", lFalse);
    } else {
        Node* thenBlock = right ? leftChild(right) : NULL;
        Node* elseBlock = right ? rightChild(right) : NULL;
        Node* thenNode = thenBlock ? leftChild(thenBlock) : NULL;
        Node* elseNode = elseBlock ? leftChild(elseBlock) : NULL;

        char* lEnd = newLabel(ctx);

        genCondition(ctx, cond, lTrue, lFalse);

        emit(ctx, "%s:\n", lTrue);
        genStatement(ctx, thenNode);
        emit(ctx, "    goto %s\n", lEnd);

        emit(ctx, "%s:\n", lFalse);
        genStatement(ctx, elseNode);

        emit(ctx, "%s:\n", lEnd);
        free(lEnd);
    }

    free(lTrue);
    free(lFalse);
}

static void genWhile(CodegenContext* ctx, Node* node) {
    Node* cond = leftChild(node);
    Node* body = rightChild(node);

    char* lStart = newLabel(ctx);
    char* lBody = newLabel(ctx);
    char* lEnd = newLabel(ctx);

    emit(ctx, "%s:\n", lStart);
    genCondition(ctx, cond, lBody, lEnd);

    emit(ctx, "%s:\n", lBody);
    genStatement(ctx, body);
    emit(ctx, "    Goto %s\n", lStart);

    emit(ctx, "%s:\n", lEnd);

    free(lStart);
    free(lBody);
    free(lEnd);
}

static void genFor(CodegenContext* ctx, Node* node) {
    Node* header = leftChild(node);
    Node* body = rightChild(node);

    if (!header) {
        return;
    }

    Node* init = leftChild(header);
    Node* condUpdate = rightChild(header);
    Node* cond = condUpdate ? leftChild(condUpdate) : NULL;
    Node* update = condUpdate ? rightChild(condUpdate) : NULL;

    if (init && strcmp(nodeType(init), "FOR_INIT") == 0) {
        Node* lhs = leftChild(init);
        Node* rhs = rightChild(init);
        Node fakeAssign = {"ASSIGN_STTMNT", NULL, lhs, rhs, init->lineno};
        genAssign(ctx, &fakeAssign);
    }

    char* lStart = newLabel(ctx);
    char* lBody = newLabel(ctx);
    char* lEnd = newLabel(ctx);

    emit(ctx, "%s:\n", lStart);
    if (cond) {
        genCondition(ctx, cond, lBody, lEnd);
    } else {
        emit(ctx, "    goto %s\n", lBody);
    }

    emit(ctx, "%s:\n", lBody);
    genStatement(ctx, body);

    if (update && strcmp(nodeType(update), "FOR_UPDATE") == 0) {
        Node* lhs = leftChild(update);
        Node* rhs = rightChild(update);
        Node fakeAssign = {"ASSIGN_STTMNT", NULL, lhs, rhs, update->lineno};
        genAssign(ctx, &fakeAssign);
    }

    emit(ctx, "    Goto %s\n", lStart);
    emit(ctx, "%s:\n", lEnd);

    free(lStart);
    free(lBody);
    free(lEnd);
}

static void genCallStatement(CodegenContext* ctx, Node* node) {
    Node* idNode = leftChild(node);
    Node* args = rightChild(node);
    int argCount = countArgs(args);

    genCallArgs(ctx, args);

    emit(ctx, "    LCall %s\n", idNode && idNode->value ? idNode->value : "");
    emit(ctx, "    PopParams %d\n", argCount * 8);
}

static void genStatement(CodegenContext* ctx, Node* node) {
    if (!node) {
        return;
    }

    const char* t = nodeType(node);

    if (strcmp(t, "BODY") == 0) {
        genNodeList(ctx, leftChild(node));
        genNodeList(ctx, rightChild(node));
        return;
    }

    if (strcmp(t, "BLOCK") == 0) {
        genStatement(ctx, leftChild(node));
        return;
    }

    if (strcmp(t, "STATEMENTS") == 0 || strcmp(t, "DECLARATIONS") == 0) {
        genNodeList(ctx, node);
        return;
    }

    if (strcmp(t, "ASSIGN_STTMNT") == 0) {
        genAssign(ctx, node);
        return;
    }

    if (strcmp(t, "CALL_STTMNT") == 0) {
        genCallStatement(ctx, node);
        return;
    }

    if (strcmp(t, "IF_STTMNT") == 0 || strcmp(t, "IF_ELSE_STTMNT") == 0) {
        genIf(ctx, node);
        return;
    }

    if (strcmp(t, "WHILE_STTMNT") == 0) {
        genWhile(ctx, node);
        return;
    }

    if (strcmp(t, "FOR_STTMNT") == 0) {
        genFor(ctx, node);
        return;
    }

    if (strcmp(t, "RETURN_STTMNT") == 0) {
        char* v = genExpr(ctx, leftChild(node));
        emit(ctx, "    Return %s\n", v);
        free(v);
        return;
    }

    if (strcmp(t, "VAR_LIST") == 0 || strcmp(t, "VAR_DECL") == 0 || strcmp(t, "PARAM_LIST") == 0 || strcmp(t, "PARAM") == 0) {
        return;
    }

    genStatement(ctx, leftChild(node));
    genStatement(ctx, rightChild(node));
}

static int countLocalDecls(Node* node) {
    if (!node) {
        return 0;
    }

    if (strcmp(nodeType(node), "VAR_DECL") == 0) {
        return 1;
    }

    return countLocalDecls(leftChild(node)) + countLocalDecls(rightChild(node));
}

static void genFunction(CodegenContext* ctx, Node* fn) {
    Node* nameNode = leftChild(fn);
    Node* body = rightChild(fn);
    const char* rawName = nameNode && nameNode->value ? nameNode->value : "anon";

    if (strcmp(rawName, "Main") == 0) {
        emit(ctx, "main:\n");
    } else {
        emit(ctx, "%s:\n", rawName);
    }

    emit(ctx, "    BeginFunc %d\n", countLocalDecls(body) * 8);
    genStatement(ctx, body);

    if (strcmp(nodeType(fn), "PROC") == 0) {
        emit(ctx, "    Return\n");
    }

    emit(ctx, "    EndFunc\n");
}

static void genTopLevel(CodegenContext* ctx, Node* node) {
    if (!node) {
        return;
    }

    const char* t = nodeType(node);

    if (strcmp(t, "Top level") == 0 || strcmp(t, "Top Level") == 0) {
        genTopLevel(ctx, leftChild(node));
        genTopLevel(ctx, rightChild(node));
        return;
    }

    if (strcmp(t, "FUNCTION") == 0 || strcmp(t, "PROC") == 0) {
        genFunction(ctx, node);
    }
}

void generate3AC(Node* root, FILE* out) {
    if (!root || !out) {
        return;
    }

    CodegenContext ctx;
    ctx.out = out;
    ctx.tempCounter = 0;
    ctx.labelCounter = 0;

    if (strcmp(nodeType(root), "PROGRAM") == 0) {
        genTopLevel(&ctx, leftChild(root));
    } else {
        genTopLevel(&ctx, root);
    }
}
