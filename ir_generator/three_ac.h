#ifndef THREE_AC_H
#define THREE_AC_H

#include <stdio.h>
#include <stddef.h>
#include "../ast/ast.h"

typedef struct {
    FILE* out;
    int tempCounter;
    int labelCounter;
    int resolvedLabelCounter;
    char* buffer;
    size_t bufferLen;
    size_t bufferCap;
} CodegenContext;

typedef struct LabelBinding {
    char* placeholder;
    int resolvedId;
    struct LabelBinding* next;
} LabelBinding;

void generate3AC(Node* root, FILE* out);

#endif
