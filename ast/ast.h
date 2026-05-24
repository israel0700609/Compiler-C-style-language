#ifndef AST_H
#define AST_H



typedef struct Node
{
    char *type;
    char *value;
    struct Node *left;
    struct Node *right;
    int lineno;
} Node;

extern Node *root;

Node *createNode(const char *type, const char *value);
Node *cloneTree(Node *node);
void addLeftChild(Node *parent, Node *child);
void addRightChild(Node *parent, Node *child);
void addLineNo(Node * node, int lineno);
void printTree(Node *node);
void freeTree(Node *node);

#endif
