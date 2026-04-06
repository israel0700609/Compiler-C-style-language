#ifndef AST_H
#define AST_H

typedef struct Node
{
    char *type;
    char *value;
    struct Node *left;
    struct Node *right;
} Node;

extern Node *root;

Node *createNode(const char *type, const char *value);
void addLeftChild(Node *parent, Node *child);
void addRightChild(Node *parent, Node *child);
static void printChildren(Node *node, const char *prefix);
void printTree(Node *node);
void freeTree(Node *node);

#endif
