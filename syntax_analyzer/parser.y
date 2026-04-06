%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

extern int yylineno;
extern char* yytext;

int yylex();
void yyerror(const char* s);

%}

%union {
    Node* node_val;
    int int_val;
    double real_val;
    char char_val;
    char* str_val;
}

/* Keywords */
%token BOOL CHAR INT REAL STRING 
%token INTPTR CHARPTR REALPTR
%token IF ELSE WHILE FOR VAR 
%token FUNC PROC RETURN NULL_TOK 

%token <int_val> TRUE_LITERAL FALSE_LITERAL INT_LITERAL
%token <real_val> REAL_LITERAL
%token <str_val> STRING_LITERAL 
%token <char_val> CHAR_LITERAL

/* Operators & ID */
%token <str_val> IDENTIFIER 
%token EQ NEQ GTE LTE AND OR 

%type <node_val> program functions function proc parameter_list non_empty_param_list type body_with_return body declarations statements statement assign_sttmnt lhs rhs decl_sttmnt var_decl_list call_sttmnt arguments non_empty_arguments_list while_sttmnt block_sttmnt return_sttmnt


/* Precedence */
%left OR
%left AND
%left EQ NEQ
%left '>' '<' GTE LTE 
%left '+' '-' 
%left '*' '/' 
%right '!'
%right '^'
%right '&'

%%

program: 
    functions {
        $$ = createNode("PROGRAM", NULL);
        addLeftChild($$, $1);
        root = $$;                       
        printf("Parsed program successfully!\n");
    }
    ;

functions: 
    function functions {
        $$ = createNode("FUNCTION_LIST", NULL); 
        addLeftChild($$, $1);
        addRightChild($$, $2);
    }
  | proc functions     {
        $$ = createNode("PROC_LIST",NULL);
        addLeftChild($$, $1);
        addRightChild($$, $2);
   }
  | function           {
        $$ = $1;
   }
  | proc               {
        $$ = $1;
   }
  ;

function:
    FUNC IDENTIFIER '(' parameter_list ')' RETURN TYPE '{' body_with_return '}' {
        $$ = createNode("FUNCTION", NULL);
        Node* idNode = createNode("IDENTIFIER", $2);
        addLeftChild(idNode, $4);
        addRightChild(idNode, $7);
        addLeftChild($$, idNode);
        addRightChild($$, $9); 
    }
    ;
proc: 
    PROC IDENTIFIER '(' parameter_list ')' '{' body '}' {
        $$ = createNode("PROC",NULL);
        Node* idNode = createNode("IDENTIFIER",$2);

        addLeftChild(idNode,$4);

        addLeftChild($$,idNode);
        addRightChild($$,$7);
     } 
    ;

parameter_list:
    non_empty_param_list { $$ = $1; }
    | { $$ = NULL; }
    ;

non_empty_param_list:
    IDENTIFIER ',' non_empty_param_list {
        Node* type = $3->left->right;
        Node* param = createNode("PARAM", NULL);

        addLeftChild(param, createNode("IDENTIFIER", $1));
        addRightChild(param, type);

        $$ = createNode("PARAM_LIST", NULL);
        addLeftChild($$, param);
        addRightChild($$, $3);
    }
    |
    IDENTIFIER ':' type ';' non_empty_param_list {
        Node* param = createNode("PARAM", NULL);
        
        addLeftChild(param, createNode("IDENTIFIER", $1));
        addRightChild(param, $3);

        $$ = createNode("PARAM_LIST", NULL);
        addLeftChild($$, param);
        addRightChild($$, $5);
    }
    |
    IDENTIFIER ':' type {
        Node* param = createNode("PARAM", NULL);
        
        addLeftChild(param, createNode("IDENTIFIER", $1));
        addRightChild(param, $3);

        $$ = createNode("PARAM_LIST", NULL);
        addLeftChild($$, param);
        addRightChild($$, NULL);
    }
    ;
type: 
    INT       { $$ = createNode("TYPE", "int"); }
    | BOOL    { $$ = createNode("TYPE", "bool"); }
    | REAL    { $$ = createNode("TYPE", "real"); }
    | CHAR    { $$ = createNode("TYPE", "char"); }
    | STRING  { $$ = createNode("TYPE", "string"); }
    
    | INTPTR  { $$ = createNode("TYPE", "int*"); }
    | CHARPTR { $$ = createNode("TYPE", "char*"); }
    | REALPTR { $$ = createNode("TYPE", "real*"); }
    ;
body_with_return:
    body return_sttmnt {
        $$ = createNode("BODY", NULL);
        addLeftChild($$, $1); 
        addRightChild($$, $2); 
    }
    | return_sttmnt {
        $$ = $1;
    }
    ;
body:
    declarations statements {
        $$ = createNode("BODY", NULL);
        addLeftChild($$, $1);
        addRightChild($$, $2);
    }
    | declarations { $$ = $1; }
    | statements   { $$ = $1; }
    | {$$ = NULL;}
    ;

declarations:
    declarations decl_sttmnt {
        $$ = createNode("DECLARATIONS", NULL);
        addLeftChild($$, $1);
        addRightChild($$, $2);
    }
    | decl_sttmnt { $$ = $1; }
    ;

statements:
    statements statement {
        $$ = createNode("STATEMENTS",NULL);
        addLeftChild($$,$1);
        addRightChild($$,$2);
    }
    |
    statement {
        $$ = $1;
    }
    ;
statement:
    assign_sttmnt {$$ = $1;}
    | call_sttmnt {$$ = $1;}
    | if_sttmnt {$$ = $1;}
    | if_else_sttmnt {$$ = $1;}
    | block_sttmnt {$$ = $1;}
    | for_sttmnt {$$ = $1;}
    | while_sttmnt {$$ = $1;}
    | return_sttmnt {$$ = $1;}
    ;
    
assign_sttmnt:
    lhs '=' rhs ';'{
        $$ = createNode("ASSIGN_STTMNT",NULL);
        addLeftChild($$,$1);
        addRightChild($$,$3);
    }
    ;
    
lhs: 
    IDENTIFIER  {
        $$ = createNode("IDENTIFIER", $1);
        }
    | IDENTIFIER '[' expression ']' {
        $$ = createNode("ARRAY_ACCESS",NULL);
        addLeftChild($$,createNode("IDENTIFIER",$1));
        addRightChild($$,$3);
        }
    | '^' IDENTIFIER {
        $$ = createNode("DEREF",NULL);
        addLeftChild($$, createNode("IDENTIFIER", $2));
        addRightChild($$,NULL);
    }
    ;   
rhs:
    expression {
        $$ = $1;
    }
    | STRING_LITERAL {
        $$ = createNode("STRING_LITERAL", $1);    }
    ;


decl_sttmnt: 
    VAR var_decl_list ';' { 
        $$ = $2; 
    }
    ;

var_decl_list:
    IDENTIFIER ',' var_decl_list {
        Node* type = $3->left->right;
        Node* id = createNode("VAR_DECL", NULL);

        addLeftChild(id, createNode("IDENTIFIER", $1));
        addRightChild(id, type);

        $$ = createNode("VAR_LIST", NULL);
        addLeftChild($$, id);
        addRightChild($$, $3);
    }
    |
    IDENTIFIER ':' type {
        Node* id = createNode("VAR_DECL", NULL);
        
        addLeftChild(id, createNode("IDENTIFIER", $1));
        addRightChild(id, $3);

        $$ = createNode("VAR_LIST", NULL);
        addLeftChild($$, id);
        addRightChild($$, NULL);
    }
    ;

call_sttmnt:
    lhs '=' IDENTIFIER '(' arguments ')' ';'{
        Node* rhss = createNode("RHS_CALL",NULL);
        addLeftChild(rhss,createNode("IDENTIFIER",$3));
        addRightChild(rhss,$5);

        $$ = createNode("CALL_STTMNT",NULL);
        addLeftChild($$,$1);
        addRightChild($$,rhss);
    }
    ;
arguments:
    non_empty_arguments_list { $$ = $1;}
    | {$$ = NULL;}
    ;
non_empty_arguments_list:
    expression ',' non_empty_arguments_list {
        $$ = createNode("ARGUMENTS_LIST",NULL);
        addLeftChild($$,$1);
        addRightChild($$,$3);
        }
    |
    expression {
        $$ = createNode("ARGUMENTS_LIST",NULL);
        addLeftChild($$,$1);
        addRightChild($$,NULL);
    }
    ;

while_sttmnt: 
    WHILE '(' expression ')' block_sttmnt {
        $$ = createNode("WHILE_STTMNT",NULL);
        addLeftChild($$,$3);
        addRightChild($$,$5);
    }
    ;
block_sttmnt:
    '{' body '}' {
        $$ = $2;
    }
    |
    statement {
        $$ = $1;
    }
    ;

return_sttmnt:
    RETURN expression ';'{
        $$ = createNode("RETURN_STTMNT",NULL);
        addLeftChild($$,$2);
        addRightChild($$,NULL);
    }
    ;



%% 

/* #include "lex.yy.c" */ 

int main() {
    printf("Starting Parser...\n");
    if (yyparse() == 0) {
        printf("Success!\n");
    } else {
        printf("Failed.\n");
    }
    return 0;
}

void yyerror(const char* s) {
    printf("Syntax Error on line %d: %s\n", yylineno, s);
}