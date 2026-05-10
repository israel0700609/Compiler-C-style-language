#include "scope.h"

// ---------------------------------------------------------
// Type & String Utilities
// ---------------------------------------------------------

// Helper function to print types correctly
const char* valTypeToString(ValType type) {
    switch(type) {
        case VAL_INT: return "int";
        case VAL_REAL: return "real";
        case VAL_BOOL: return "bool";
        case VAL_CHAR: return "char";
        case VAL_STRING: return "string";
        case VAL_NULL: return "null";
        default: return "unknown";
    }
}

TypeInfo parseType(const char* typeStr) {
    TypeInfo ti = {VAL_UNKNOWN, 0};
    if (!typeStr) return ti;

    char baseType[64] = {0};
    strncpy(baseType, typeStr, 63);
    
    int len = strlen(baseType);
    if (len > 0 && baseType[len - 1] == '*') {
        ti.is_ptr = 1;
        baseType[len - 1] = '\0'; // Remove '*' to check base type
    }

    if (strcmp(baseType, "int") == 0) ti.base = VAL_INT;
    else if (strcmp(baseType, "real") == 0 || strcmp(baseType, "float") == 0) ti.base = VAL_REAL;
    else if (strcmp(baseType, "bool") == 0) ti.base = VAL_BOOL;
    else if (strcmp(baseType, "char") == 0) ti.base = VAL_CHAR;
    else if (strcmp(baseType, "string") == 0) ti.base = VAL_STRING;
    
    return ti;
}

int matchTypes(TypeInfo t1, TypeInfo t2) {
    return (t1.base == t2.base) && (t1.is_ptr == t2.is_ptr);
}

// ---------------------------------------------------------
// Search & Lookups
// ---------------------------------------------------------

int isLocal(Scope* scope, char* name) {
    if (!scope || !name) return 0;
    Symbol* curr = scope->symbols;
    while (curr) {
        if (strcmp(curr->name, name) == 0) return 1;
        curr = curr->next;
    }
    return 0;
}

Symbol* getSymbol(Scope* scope, char* name, SymKind kind) {
    Scope* currScope = scope;
    while (currScope) {
        Symbol* currSym = currScope->symbols;
        while (currSym) {
            if (currSym->kind == kind && strcmp(currSym->name, name) == 0) {
                return currSym;
            }
            currSym = currSym->next;
        }
        currScope = currScope->parent;
    }
    return NULL;
}

Symbol* getFunc(Scope* scope, char* name) {
    return getSymbol(scope, name, SYM_FUNC);
}

Symbol* getVar(Scope* scope, char* name) {
    // Variables can be SYM_VAR or SYM_PARAM
    Scope* currScope = scope;
    while (currScope) {
        Symbol* currSym = currScope->symbols;
        while (currSym) {
            if ((currSym->kind == SYM_VAR || currSym->kind == SYM_PARAM) && strcmp(currSym->name, name) == 0) {
                return currSym;
            }
            currSym = currSym->next;
        }
        currScope = currScope->parent;
    }
    return NULL;
}

Symbol* getLocalVar(Scope* scope, char* name) {
    if (!scope || !name) return NULL;
    Symbol* currSym = scope->symbols;
    while (currSym) {
        if ((currSym->kind == SYM_VAR || currSym->kind == SYM_PARAM) && strcmp(currSym->name, name) == 0) {
            return currSym;
        }
        currSym = currSym->next;
    }
    return NULL;
}

SymKind* getLocalKind(Scope* scope, char* name, SymKind kind) {
    if (!scope || !name) return NULL;
    Symbol* currSym = scope->symbols;
    while (currSym) {
        if (currSym->kind == kind && strcmp(currSym->name, name) == 0) {
            return &(currSym->kind); // Returns a pointer to the enum
        }
        currSym = currSym->next;
    }
    return NULL;
}

Symbol* getLastReturn(Scope* scope) {
    /* 
     * NOTE: Since 'Scope' doesn't explicitly point to its owner function,
     * For now, it searches upwards for the first SYM_FUNC it can find.
     */
    Scope* currScope = scope;
    while (currScope) {
        Symbol* currSym = currScope->symbols;
        while (currSym) {
            if (currSym->kind == SYM_FUNC) {
                return currSym;
            }
            currSym = currSym->next;
        }
        currScope = currScope->parent;
    }
    return NULL;
}


TypeInfo getExprType(Scope* scope, Node* node) {
    TypeInfo unknown = {VAL_UNKNOWN, 0};
    if (!node || !node->type) return unknown;

    const char* t = node->type;

    if (strcmp(t, "INT_LITERAL") == 0)   { TypeInfo r = {VAL_INT,    0}; return r; }
    if (strcmp(t, "REAL_LITERAL") == 0)  { TypeInfo r = {VAL_REAL,   0}; return r; }
    if (strcmp(t, "CHAR_LITERAL") == 0)  { TypeInfo r = {VAL_CHAR,   0}; return r; }
    if (strcmp(t, "BOOL_LITERAL") == 0)  { TypeInfo r = {VAL_BOOL,   0}; return r; }
    if (strcmp(t, "STRING_LITERAL") == 0){ TypeInfo r = {VAL_STRING, 0}; return r; }
    if (strcmp(t, "NULL") == 0)          { TypeInfo r = {VAL_NULL,   0}; return r; }

    if (strcmp(t, "IDENTIFIER") == 0) {
        Symbol* sym = getVar(scope, node->value);
        if (!sym) return unknown;
        return sym->type;
    }

    if (strcmp(t, "ARRAY_ACCESS") == 0) { TypeInfo r = {VAL_CHAR, 0}; return r; }

    if (strcmp(t, "FUNC_CALL") == 0) {
        Node* idNode = node->left;
        if (!idNode || !idNode->value) return unknown;
        Symbol* sym = getFunc(scope, idNode->value);
        if (!sym) return unknown;
        return sym->type;
    }

    if (strcmp(t, "STRLEN") == 0) { TypeInfo r = {VAL_INT,  0}; return r; }
    if (strcmp(t, "NOT")    == 0) { TypeInfo r = {VAL_BOOL, 0}; return r; }

    if (strcmp(t, "NEG") == 0 || strcmp(t, "POS") == 0)
        return getExprType(scope, node->left);

    if (strcmp(t, "DEREF") == 0) {
        TypeInfo inner = getExprType(scope, node->left);
        TypeInfo r = {inner.base, 0}; return r;
    }
    if (strcmp(t, "ADDR_OF") == 0) {
        TypeInfo inner = getExprType(scope, node->left);
        TypeInfo r = {inner.base, 1}; return r;
    }

    if (strcmp(t, "ADD") == 0 || strcmp(t, "SUB") == 0) {
        TypeInfo left = getExprType(scope, node->left);
        TypeInfo right = getExprType(scope, node->right);
        if (left.is_ptr) return left;
        if (right.is_ptr) return right;
        TypeInfo r = {(left.base == VAL_REAL || right.base == VAL_REAL) ? VAL_REAL : VAL_INT, 0};
        return r;
    }
    if (strcmp(t, "MUL") == 0 || strcmp(t, "DIV") == 0) {
        TypeInfo left = getExprType(scope, node->left);
        TypeInfo right = getExprType(scope, node->right);
        TypeInfo r = {(left.base == VAL_REAL || right.base == VAL_REAL) ? VAL_REAL : VAL_INT, 0};
        return r;
    }

    if (strcmp(t, "AND") == 0 || strcmp(t, "OR")  == 0 ||
        strcmp(t, "GT")  == 0 || strcmp(t, "LT")  == 0 ||
        strcmp(t, "GTE") == 0 || strcmp(t, "LTE") == 0 ||
        strcmp(t, "EQ")  == 0 || strcmp(t, "NEQ") == 0) {
        TypeInfo r = {VAL_BOOL, 0}; return r;
    }

    return unknown;
}

// ---------------------------------------------------------
// Scope Management
// ---------------------------------------------------------

Scope* enterScope(Scope* current) {
    Scope* newScope = (Scope*)malloc(sizeof(Scope));
    if (!newScope) {
        fprintf(stderr, "Fatal: Memory allocation failed for new scope.\n");
        exit(1);
    }
    newScope->parent = current;
    newScope->symbols = NULL;
    newScope->level = current ? current->level + 1 : 0;
    
    return newScope;
}

Scope* exitScope(Scope* current) {
    if (!current) return NULL;
    Scope* parent = current->parent;
    freeScope(current); // Frees the current scope and its symbols
    return parent;
}

void addSymbol(Scope* scope, Symbol* sym) {
    if (!scope || !sym) return;
    // Insert at the head of the linked list for O(1) insertion
    sym->next = scope->symbols;
    scope->symbols = sym;
}

void addParam(Param** list, char* name, TypeInfo type) {
    if (!list || !name) return;
    
    Param* newParam = (Param*)malloc(sizeof(Param));
    if (!newParam) return;
    
    // Using strdup to ensure the parameter name is safely stored
    newParam->name = strdup(name); 
    newParam->type = type;
    newParam->next = NULL;

    // Append to the end of the list to maintain parameter order
    if (*list == NULL) {
        *list = newParam;
    } else {
        Param* curr = *list;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newParam;
    }
}
// ---------------------------------------------------------
// Printing
// ---------------------------------------------------------

void printParams(Param* params) {
    Param* curr = params;
    while (curr) {
        printf("%s %s%s", valTypeToString(curr->type.base), curr->type.is_ptr ? "*" : "", curr->name);
        if (curr->next) printf(", ");
        curr = curr->next;
    }
}

void printSymbol(Symbol* sym) {
    if (!sym) return;
    printf("  Name: %s | Kind: %d | Type: %s%s", 
            sym->name, 
            sym->kind, 
            valTypeToString(sym->type.base), 
            sym->type.is_ptr ? "*" : "");

    if (sym->kind == SYM_FUNC) {
        printf(" | Params: (");
        printParams(sym->details.func.params);
        printf(") | Count: %d", sym->details.func.count);
    } else if (sym->kind == SYM_VAR || sym->kind == SYM_PARAM) {
        if (sym->details.var.is_array) printf(" | is_array: true");
    }
    printf("\n");
}

void printScope(Scope* scope) {
    if (!scope) {
        printf("Scope is NULL\n");
        return;
    }
    printf("=== Scope Level: %d ===\n", scope->level);
    Symbol* curr = scope->symbols;
    if (!curr) {
        printf("  (Empty Scope)\n");
    }
    while (curr) {
        printSymbol(curr);
        curr = curr->next;
    }
    printf("=======================\n");
}

// ---------------------------------------------------------
// Memory Cleanup
// ---------------------------------------------------------

void freeParams(Param* head) {
    Param* curr = head;
    while (curr) {
        Param* temp = curr;
        curr = curr->next;
        if (temp->name) free(temp->name);
        free(temp);
    }
}

void freeSymbols(Symbol* head) {
    Symbol* curr = head;
    while (curr) {
        Symbol* temp = curr;
        curr = curr->next;
        
        if (temp->name) free(temp->name); 
        
        if (temp->kind == SYM_FUNC && temp->details.func.params) {
            freeParams(temp->details.func.params);
        }
        
        free(temp);
    }
}

void freeScope(Scope* scope) {
    if (!scope) return;
    freeSymbols(scope->symbols);
    free(scope);
}

void freeAllScopes(Scope* top) {
    Scope* curr = top;
    while (curr) {
        Scope* temp = curr;
        curr = curr->parent;
        freeScope(temp);
    }
}