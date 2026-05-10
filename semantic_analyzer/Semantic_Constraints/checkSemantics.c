#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BluePrintFiles/scope.h"
#include "../../ast/ast.h"


#include "checks/utils.c"
#include "checks/params.c"
#include "checks/calls.c"
#include "checks/statements.c"

void runSemanticChecks(Node* root) {
    Scope* globalScope = enterScope(NULL);
    foundMainProcedure = 0;

    checkNodeSemantics(root, globalScope);

    if (!foundMainProcedure) {
        printf("Semantic Error: Procedure 'Main' is missing from the program.\n");
        errorOccurred = 1;
    }
    if (errorOccurred) {
        exit(1);
    }
    exitScope(globalScope);
}