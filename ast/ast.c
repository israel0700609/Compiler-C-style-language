#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

Node *root = NULL;

Node *createNode(const char *type, const char *value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type ? strdup(type) : NULL;
    node->value = value ? strdup(value) : NULL;
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

    printf("%s", prefix);
    printf("%s", is_right ? "└── " : "├── ");

    if (node->value)
        printf("%s(%s)\n", node->type, node->value);
    else
        printf("%s\n", node->type);

    int plen = strlen(prefix);
    char *new_prefix = (char *)malloc(plen + 8);
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

    if (node->value)
        printf("%s(%s)\n", node->type, node->value);
    else
        printf("%s\n", node->type);

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
