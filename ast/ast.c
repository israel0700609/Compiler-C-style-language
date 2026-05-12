#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;

Node *root = NULL;

static void printSubtree(Node *node, const char *prefix, int isLast);

static char *duplicateString(const char *src) {
  if (!src)
    return NULL;

  size_t len = strlen(src) + 1;
  char *dst = (char *)malloc(len);
  if (!dst)
    return NULL;

  memcpy(dst, src, len);
  return dst;
}

Node *createNode(const char *type, const char *value) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node)
    return NULL;

  node->type = duplicateString(type);
  node->value = duplicateString(value);
  node->left = NULL;
  node->right = NULL;
  node->lineno = yylineno;
  return node;
}

void addLeftChild(Node *parent, Node *child) {
  if (parent)
    parent->left = child;
}

void addRightChild(Node *parent, Node *child) {
  if (parent)
    parent->right = child;
}


static void addLineNo(Node* node, int lineno){
  if(node && lineno >= 0){
    node->lineno = lineno;
  }
}

static void printSubtree(Node *node, const char *prefix, int isLast) {
  if (!node)
    return;

  const char *nodeType = node->type ? node->type : "<null-type>";

  printf("%s", prefix);
  printf("%s", isLast ? "`-- " : "|-- ");

  if (node->value)
    printf("%s(%s)\n", nodeType, node->value);
  else
    printf("%s\n", nodeType);

  size_t plen = strlen(prefix);
  char *new_prefix = (char *)malloc(plen + 5);
  if (!new_prefix)
    return;

  memcpy(new_prefix, prefix, plen);
  memcpy(new_prefix + plen, isLast ? "    " : "|   ", 5);

  if (node->left && node->right) {
    printSubtree(node->left, new_prefix, 0);
    printSubtree(node->right, new_prefix, 1);
  } else if (node->left) {
    printSubtree(node->left, new_prefix, 1);
  } else if (node->right) {
    printSubtree(node->right, new_prefix, 1);
  }

  free(new_prefix);
}

void printTree(Node *node) {
  if (!node) {
    printf("(empty tree)\n");
    return;
  }

  const char *nodeType = node->type ? node->type : "<null-type>";

  if (node->value)
    printf("%s(%s)\n", nodeType, node->value);
  else
    printf("%s\n", nodeType);

  if (node->left && node->right) {
    printSubtree(node->left, "", 0);
    printSubtree(node->right, "", 1);
  } else if (node->left) {
    printSubtree(node->left, "", 1);
  } else if (node->right) {
    printSubtree(node->right, "", 1);
  }
}

void freeTree(Node *node) {
  if (!node)
    return;
  freeTree(node->left);
  freeTree(node->right);
  free(node->type);
  free(node->value);
  free(node);
}