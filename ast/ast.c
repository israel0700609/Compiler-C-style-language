#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Node *root = NULL;

static void printChildren(Node *node, const char *prefix);

static char *duplicateString(const char *src)
{
    if (!src)
        return NULL;

    size_t len = strlen(src) + 1;
    char *dst = (char *)malloc(len);
    if (!dst)
        return NULL;

    memcpy(dst, src, len);
    return dst;
}

Node *createNode(const char *type, const char *value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
        return NULL;

    node->type = duplicateString(type);
    node->value = duplicateString(value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addLeftChild(Node *parent, Node *child)
{
    if (parent)
        parent->left = child;
}

void addRightChild(Node *parent, Node *child)
{
    if (parent)
        parent->right = child;
}

static void printTreeHelper(Node *node, const char *prefix, int is_right)
{
    if (!node)
        return;

    const char *nodeType = node->type ? node->type : "<null-type>";

    printf("%s", prefix);
    printf("%s", is_right ? "└── " : "├── ");

    if (node->value)
        printf("%s(%s)\n", nodeType, node->value);
    else
        printf("%s\n", nodeType);

    int plen = strlen(prefix);
    char *new_prefix = (char *)malloc(plen + 8);
    if (!new_prefix)
        return;
    strcpy(new_prefix, prefix);
    strcat(new_prefix, is_right ? "    " : "│   ");

    printChildren(node, new_prefix);

    free(new_prefix);
}

static void printChildren(Node *node, const char *prefix)
{
    if (node->left && node->right)
    {
        printTreeHelper(node->left, prefix, 0);
        printTreeHelper(node->right, prefix, 1);
    }
    else if (node->left)
    {
        printTreeHelper(node->left, prefix, 1);
    }
    else if (node->right)
    {
        printTreeHelper(node->right, prefix, 1);
    }
}

void printTree(Node *node)
{
    if (!node)
    {
        printf("(empty tree)\n");
        return;
    }

    const char *nodeType = node->type ? node->type : "<null-type>";

    if (node->value)
        printf("%s(%s)\n", nodeType, node->value);
    else
        printf("%s\n", nodeType);

    printChildren(node, "");
}

void freeTree(Node *node)
{
    if (!node)
        return;
    freeTree(node->left);
    freeTree(node->right);
    free(node->type);
    free(node->value);
    free(node);
}