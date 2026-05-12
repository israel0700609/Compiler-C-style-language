#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

#include "../../ast/ast.h"

typedef enum {
    SYM_VAR,
    SYM_PARAM,
    SYM_FUNC,
    SYM_PROC
} SymKind;

typedef enum {
    SEM_OK = 0,
    SEM_NEW_SCOPE = 1,
    SEM_ERROR = -1
} SemStatus;

typedef enum {
    VAL_INT,
    VAL_REAL,
    VAL_BOOL,
    VAL_CHAR,
    VAL_STRING,
    VAL_NULL,
    VAL_UNKNOWN
} ValType;

typedef struct {
    ValType base;
    int is_ptr;
} TypeInfo;

typedef struct Param {
    char* name;
    TypeInfo type;
    struct Param* next;
} Param;

typedef struct Symbol {
    char* name;
    SymKind kind;
    TypeInfo type;

    union {
        struct {
            Param* params; 
            int count;
        } func;

        struct {
            int is_array;
        } var; 
    } details;

    struct Symbol* next; 
} Symbol;

typedef struct Scope {
    struct Scope* parent; 
    Symbol* symbols;     
    int level;            
} Scope;



TypeInfo parseType(const char* typeStr); // Convert string type into structured type
int isLocal(Scope* scope, char* name); // Checks if the income name var is local in the income scope 
int matchTypes(TypeInfo t1, TypeInfo t2); // Checks if the types are equally semantic

Symbol* getSymbol(Scope* scope, char* name, SymKind kind); // Search the income symbol in the income Scope and return it 
Symbol* getFunc(Scope* scope, char* name); // Search the income func name in the income Scope and return the symbol
Symbol* getVar(Scope* scope, char* name); // Search the income var name in the income Scope and return the symbol
Symbol* getLocalVar(Scope* scope, char* name); //Search the income local var name in the income scope and return the symbol
SymKind* getLocalKind(Scope* scope, char* name, SymKind kind); // Search the income symkind in this local scope 

TypeInfo getExprType(Scope* scope, Node* node); // Evaluate the exp type  (must be done by yuval)
Symbol* getLastReturn(Scope* scope); // Searching for the last return(func) scope



Scope* enterScope(Scope* current); // Create new scope link the current to his parent and return the new scope
Scope* exitScope(Scope* current); // Free the used vars and return the parent scope

void addSymbol(Scope* scope, Symbol* sym); // Add the income sym into the income scope likedlist
void addParam(Param** list, char* name, TypeInfo type); // Add or define the income param into the param linkedlist



void printScope(Scope* scope); // Prints the local scope
void printParams(Param* params); // Prints params
void printSymbol(Symbol* sym); // Prints symbol 


// Free allocated mem
void freeParams(Param* head);
void freeSymbols(Symbol* head);
void freeScope(Scope* scope);
void freeAllScopes(Scope* top);
