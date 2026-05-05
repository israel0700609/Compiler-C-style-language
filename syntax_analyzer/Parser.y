%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast/ast.h"
extern int yylineno;
extern char* yytext;
extern Node* root;

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

%type <node_val> program functions function proc parameter_list non_empty_param_list type body declarations statements statement assign_sttmnt lhs rhs decl_sttmnt var_decl_list call_sttmnt arguments non_empty_arguments_list if_sttmnt for_sttmnt while_sttmnt block_sttmnt return_sttmnt expression




/* Precedence */

%nonassoc IFX
%nonassoc ELSE

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
        $$ = createNode("Top level", NULL);
        addLeftChild($$, $1);
        addRightChild($$, $2);
    }
  | proc functions     {
        $$ = createNode("Top level",NULL);
        addLeftChild($$, $1);
        addRightChild($$, $2);
   }
  | function           {
        $$ = createNode("Top level", NULL);
        addLeftChild($$, $1);
        addRightChild($$, NULL);
   }
  | proc               {
        $$ = createNode("Top Level", NULL);
        addLeftChild($$, $1);
        addRightChild($$, NULL);
   }
  ;

function:
    FUNC IDENTIFIER '(' parameter_list ')' RETURN type '{' body '}' {
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
        Node* original_type = $3->left->right;
        Node* cloned_type = createNode(original_type->type, original_type->value);
        
        Node* param = createNode("PARAM", NULL);
        addLeftChild(param, createNode("IDENTIFIER", $1));
        addRightChild(param, cloned_type); /* משתמשים בשיבוט! */

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
    | STRING '[' INT_LITERAL ']' { char buf[32]; sprintf(buf,"%d",$3); $$ = createNode("STRING_ARRAY_TYPE", buf);}
    
    | INTPTR  { $$ = createNode("TYPE", "int*"); }
    | CHARPTR { $$ = createNode("TYPE", "char*"); }
    | REALPTR { $$ = createNode("TYPE", "real*"); }
    
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
    | block_sttmnt {$$ = $1;}
    | for_sttmnt {$$ = $1;}
    | while_sttmnt {$$ = $1;}
    | return_sttmnt {$$ = $1;}
    | function {$$ = $1;}
    | proc {$$ = $1;}
    ;
assign_sttmnt:
    lhs '=' rhs ';'{
        $$ = createNode("ASSIGN_STTMNT",NULL);
        addLeftChild($$,$1);
        addRightChild($$,$3);
    }
    ;
    
lhs: 
    IDENTIFIER  { $$ = createNode("IDENTIFIER", $1); }
    | IDENTIFIER '[' expression ']' {
        $$ = createNode("ARRAY_ACCESS", NULL);
        addLeftChild($$, createNode("IDENTIFIER", $1));
        addRightChild($$, $3);
    }
    | '^' IDENTIFIER { 
        $$ = createNode("DEREF", NULL); 
        addLeftChild($$, createNode("IDENTIFIER", $2)); 
        addRightChild($$, NULL); 
    }
    | '^' IDENTIFIER '[' expression ']' {
        Node* arr = createNode("ARRAY_ACCESS", NULL);
        addLeftChild(arr, createNode("IDENTIFIER", $2));
        addRightChild(arr, $4);
        $$ = createNode("DEREF", NULL); 
        addLeftChild($$, arr);
        addRightChild($$, NULL);
    }
    | '^' '(' expression ')' {
        $$ = createNode("DEREF", NULL); 
        addLeftChild($$, $3); 
        addRightChild($$, NULL); 
    }
    ;
rhs:
    expression {
        $$ = $1;
    }
    ;

expression:
      expression OR expression { $$ = createNode("OR",  NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression AND expression { $$ = createNode("AND", NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression EQ expression  { $$ = createNode("EQ",  NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression NEQ expression { $$ = createNode("NEQ", NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression '>' expression { $$ = createNode("GT",  NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression '<' expression { $$ = createNode("LT",  NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression GTE expression { $$ = createNode("GTE", NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression LTE expression { $$ = createNode("LTE", NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression '+' expression { $$ = createNode("ADD", NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression '-' expression { $$ = createNode("SUB", NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression '*' expression { $$ = createNode("MUL", NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | expression '/' expression { $$ = createNode("DIV", NULL); addLeftChild($$,$1); addRightChild($$,$3); }
    | '!' expression { $$ = createNode("NOT",  NULL); addLeftChild($$,$2); addRightChild($$,NULL); }
    | '-' expression %prec '!' { $$ = createNode("NEG",  NULL); addLeftChild($$,$2); addRightChild($$,NULL); }
    | '+' expression %prec '!' { $$ = createNode("POS",  NULL); addLeftChild($$,$2); addRightChild($$,NULL); }
    | '^' IDENTIFIER { 
        $$ = createNode("DEREF", NULL); 
        addLeftChild($$, createNode("IDENTIFIER", $2)); 
    }
    | '^' IDENTIFIER '[' expression ']' { 
        Node* arr = createNode("ARRAY_ACCESS", NULL);
        addLeftChild(arr, createNode("IDENTIFIER", $2));
        addRightChild(arr, $4);
        $$ = createNode("DEREF", NULL); 
        addLeftChild($$, arr); 
    }
    | '^' '(' expression ')' { 
        $$ = createNode("DEREF", NULL); 
        addLeftChild($$, $3); 
    }

    | '&' IDENTIFIER { $$ = createNode("ADDR_OF",NULL); addLeftChild($$,createNode("IDENTIFIER",$2)); addRightChild($$,NULL); }
    | '&' IDENTIFIER '[' expression ']' { 
        Node* arr = createNode("ARRAY_ACCESS", NULL);
        addLeftChild(arr, createNode("IDENTIFIER", $2));
        addRightChild(arr, $4);
        $$ = createNode("ADDR_OF", NULL);
        addLeftChild($$, arr);
    }
    | '(' expression ')' { $$ = $2; }
    
    | '|' expression '|' { $$ = createNode("STRLEN", NULL); addLeftChild($$, $2); } 
    
    | IDENTIFIER '[' expression ']'{ $$ = createNode("ARRAY_ACCESS",NULL); addLeftChild($$,createNode("IDENTIFIER",$1)); addRightChild($$,$3); }
    | IDENTIFIER { $$ = createNode("IDENTIFIER",$1); }
    | IDENTIFIER '(' arguments ')' { 
        $$ = createNode("FUNC_CALL", NULL); 
        addLeftChild($$, createNode("IDENTIFIER", $1)); 
        addRightChild($$, $3); 
    }
    | INT_LITERAL { char buf[32]; sprintf(buf,"%d",$1);  $$ = createNode("INT_LITERAL",  buf); }
    | REAL_LITERAL { char buf[64]; sprintf(buf,"%g",$1);  $$ = createNode("REAL_LITERAL", buf); }
    | CHAR_LITERAL { char buf[4];  buf[0]=$1; buf[1]='\0'; $$ = createNode("CHAR_LITERAL",buf); }
    | TRUE_LITERAL { $$ = createNode("BOOL_LITERAL","true"); }
    | FALSE_LITERAL { $$ = createNode("BOOL_LITERAL","false"); }
    
    | STRING_LITERAL { $$ = createNode("STRING_LITERAL", $1); } 
    
    | NULL_TOK { $$ = createNode("NULL",NULL); }
    ;
decl_sttmnt: 
    VAR var_decl_list ';' { 
        $$ = $2; 
    }
    ;

var_decl_list:
    IDENTIFIER ',' var_decl_list {
        Node* original_type = $3->left->right;
        Node* cloned_type = createNode(original_type->type, original_type->value);
        
        Node* id = createNode("VAR_DECL", NULL);
        addLeftChild(id, createNode("IDENTIFIER", $1));
        addRightChild(id, cloned_type); 

        $$ = createNode("VAR_LIST", NULL);
        addLeftChild($$, id);
        addRightChild($$, $3);
    }    |
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
    IDENTIFIER '(' arguments ')' ';' {
        $$ = createNode("CALL_STTMNT", NULL);
        addLeftChild($$, createNode("IDENTIFIER", $1));
        addRightChild($$, $3);
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

if_sttmnt:
    IF '(' expression ')' statement %prec IFX {
        $$ = createNode("IF_STTMNT", NULL);
        addLeftChild($$, $3); 
        
        Node* then_block = createNode("THEN", NULL);
        addLeftChild(then_block, $5);
        addRightChild($$, then_block);
    }
    | IF '(' expression ')' statement ELSE statement {
        $$ = createNode("IF_ELSE_STTMNT", NULL);
        
        Node* then_block = createNode("THEN", NULL);
        addLeftChild(then_block, $5);
        
        Node* else_block = createNode("ELSE", NULL);
        addLeftChild(else_block, $7);
        
        Node* branches = createNode("IF_BRANCHES", NULL);
        addLeftChild(branches, then_block);
        addRightChild(branches, else_block);
        
        addLeftChild($$, $3);
        addRightChild($$, branches);
    }
    ;

for_sttmnt:
    FOR '(' lhs '=' rhs ';' expression ';' lhs '=' rhs ')' statement {
        $$ = createNode("FOR_STTMNT",NULL);

        Node* init = createNode("FOR_INIT",NULL);
        addLeftChild(init,$3);
        addRightChild(init,$5);

        Node* update = createNode("FOR_UPDATE",NULL);
        addLeftChild(update,$9);
        addRightChild(update,$11);

        Node* cond_update = createNode("FOR_COND_UPDATE",NULL);
        addLeftChild(cond_update,$7);
        addRightChild(cond_update,update);

        Node* header = createNode("FOR_HEADER",NULL);
        addLeftChild(header,init);
        addRightChild(header,cond_update);

        addLeftChild($$,header);
        addRightChild($$,$13);
    }
    ;

while_sttmnt:
    WHILE '(' expression ')' statement {
        $$ = createNode("WHILE_STTMNT",NULL);
        addLeftChild($$,$3);
        addRightChild($$,$5);
    }
    ;
block_sttmnt:
    '{' body '}' {
        $$ = createNode("BLOCK", NULL);
        addLeftChild($$, $2);
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
        printf("Success!\n\n");
        printf("=== Abstract Syntax Tree ===\n");
        printTree(root);
        freeTree(root);
    } 
    return 0;
}

void yyerror(const char* s) {
    printf("Syntax Error on line %d: %s: unexpected token '%s' \n ", yylineno, s,yytext);
}