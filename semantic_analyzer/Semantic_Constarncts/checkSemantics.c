#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scope.h"
#include "ast.h" 


int foundMainProcedure = 0;

void runSemanticChecks(ASTNode* root) {
    Scope* globalScope = enterScope(NULL); 
    foundMainProcedure = 0;

    checkNodeSemantics(root, globalScope);

    if (!foundMainProcedure) {
        printf("Semantic Error: Procedure 'Main' is missing from the program.\n");
        exit(1);
    }

    exitScope(globalScope);
}

void checkNodeSemantics(ASTNode* node, Scope* currentScope) {
    if (!node) return;

  
    if (strcmp(node->type, "VAR_DECL") == 0) { 
        char* varName = node->value; 
        
      
        if (isLocal(currentScope, varName)) {
            printf("Semantic Error: Variable '%s' is already defined in the current scope.\n", varName);
            exit(1);
        }

   
        Symbol* newVar = (Symbol*)malloc(sizeof(Symbol));
        newVar->name = strdup(varName);
        newVar->kind = SYM_VAR;
        addSymbol(currentScope, newVar);
    }


    else if (strcmp(node->type, "FUNC_DECL") == 0 || strcmp(node->type, "PROC_DECL") == 0) {
        char* funcName = node->value;

        if (isLocal(currentScope, funcName)) {
            printf("Semantic Error: Function or Procedure '%s' is already defined.\n", funcName);
            exit(1);
        }

        if (strcmp(funcName, "Main") == 0) {
            foundMainProcedure = 1;

            if (strcmp(node->type, "FUNC_DECL") == 0) {
                printf("Semantic Error: 'Main' must be a procedure, not a function.\n");
                exit(1);
            }
            
            
            if (node->children[0] != NULL) { 
                printf("Semantic Error: Procedure 'Main' cannot take arguments.\n");
                exit(1);
            }
        }

        Symbol* newFunc = (Symbol*)malloc(sizeof(Symbol));
        newFunc->name = strdup(funcName);
        newFunc->kind = (strcmp(node->type, "FUNC_DECL") == 0) ? SYM_FUNC : SYM_PROC;
        addSymbol(currentScope, newFunc);

        Scope* funcScope = enterScope(currentScope);

        for (int i = 0; i < node->num_children; i++) {
            checkNodeSemantics(node->children[i], funcScope);
        }

        exitScope(funcScope); 
        return; 
    }

   
    else if (strcmp(node->type, "VARIABLE") == 0) {
        char* varName = node->value;
        
        Symbol* sym = getVar(currentScope, varName);
        if (sym == NULL) {
            printf("Semantic Error: Variable '%s' is used before it is defined.\n", varName);
            exit(1);
        }
    }


    else if (strcmp(node->type, "CALL") == 0) {
        char* funcName = node->value;
        
        Symbol* symFunc = getSymbol(currentScope, funcName, SYM_FUNC);
        Symbol* symProc = getSymbol(currentScope, funcName, SYM_PROC);
        
        if (symFunc == NULL && symProc == NULL) {
            printf("Semantic Error: Function/Procedure '%s' is called before it is defined.\n", funcName);
            exit(1);
        }
    }

    for (int i = 0; i < node->num_children; i++) {
        if (node->children[i] != NULL) {
            checkNodeSemantics(node->children[i], currentScope);
        }
    }
}