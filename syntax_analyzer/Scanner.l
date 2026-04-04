%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "y.tab.h" 

%}

%option yylineno
%option noyywrap

%x COMMENT 

/* --- ביטויים רגולריים בסיסיים לעזר --- */
ALPHA      [a-zA-Z]
DIGIT      [0-9]
HEX        [0-9a-fA-F]

%%
 /* --- טיפול בהערות --- */

"/%"            { BEGIN(COMMENT); } 
<COMMENT>.      {/* בולעים את כל התווים הרגילים */}  
<COMMENT>\n      { /* בולעים ירידות שורה */ }
<COMMENT>"%/"   { BEGIN(INITIAL); }

 /* --- התעלמות מרווחים וירידות שורה --- */
[ \t\r\n]+        { /* מתעלמים מרווחים וטאבים */ }

 /* --- מילות מפתח מתוך מסמך השפה --- */
"bool"          { return BOOL; }
"char"          { return CHAR; }
"int"           { return INT; }
"real"          { return REAL; }
"string"        { return STRING; }
"int*"          { return INTPTR; }
"char*"         { return CHARPTR; }
"real*"         { return REALPTR; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"var"           { return VAR; }
"func"          { return FUNC; }
"proc"          { return PROC; }
"return"        { return RETURN; }
"null"          { return NULL_TOK; }

 /* --- ליטרלים (Literals) --- */

 /* בוליאני */
"true"          { 
    yylval.int_val = 1;
    return TRUE_LITERAL; 
}
"false"         { 
    yylval.int_val = 0;
    return FALSE_LITERAL; 
}

 /* מספרים שלמים: עשרוני או הקסדצימלי */
0|[1-9]{DIGIT}* { 
    yylval.int_val = atoi(yytext);    
    return INT_LITERAL;
}

0[xX]{HEX}+     { 
    yylval.int_val = strtol(yytext + 2, NULL, 16);
    return INT_LITERAL; 
}

 /* מספרים ממשיים: תומך בנקודה עשרונית, כתיב מדעי (ללא סימן +/- מוביל כדי למנוע התנגשות עם חיסור) */
([0-9]+\.[0-9]*|\.[0-9]+)([eE][-+]?[0-9]+)?|[0-9]+[eE][-+]?[0-9]+ { 
    yylval.real_val = atof(yytext);    
    return REAL_LITERAL; 
}

 /* מחרוזות: מוקפות במרכאות כפולות, לא נשברות שורה */
\"([^\"\n\\]|\\.)*\" { 
    int len = yyleng - 2;
    char* str = (char*)malloc(len + 1);
    strncpy(str, yytext + 1, len);
    str[len] = '\0';
    yylval.str_val = str;
    return STRING_LITERAL; 
}

 /* תווים (char): תומכים בתווי Escape */
\'([^'\n\\]|\\.)\'   { 
    if(yytext[1] != '\\') {
        yylval.char_val = yytext[1];
    } else {
        switch(yytext[2]){
            case 'n': yylval.char_val = '\n'; break;
            case 't': yylval.char_val = '\t'; break;
            case 'r': yylval.char_val = '\r'; break;
            case '\\': yylval.char_val = '\\'; break;
            case '\'': yylval.char_val = '\''; break;
            default:  yylval.char_val = yytext[2]; break; 
        }
    }
    return CHAR_LITERAL;
}

 /* מזהים (Identifiers) */
{ALPHA}({ALPHA}|{DIGIT}|"_")* { 
    yylval.str_val = (char*)malloc(strlen(yytext) + 1);
    strcpy(yylval.str_val, yytext);
    return IDENTIFIER; }

 /* --- אופרטורים ותווים מיוחדים --- */
"=="            { return EQ; }
"!="            { return NEQ; }
">="            { return GTE; }
"<="            { return LTE; }
"&&"            { return AND; }
"||"            { return OR; }

 /* תווים בודדים */
"+"|"-"|"*"|"/"|">"|"<"|"!"|"="|"^"|"&"|"|"|";"|":"|","|"["|"]"|"{"|"}"|"("|")" { 
    return yytext[0]; 
}

 /* --- שגיאות לקסיקליות --- */
.               { 
    printf("Lexical Error on line %d: Unrecognized character '%s'\n", yylineno, yytext); 
    exit(1); 
}

%%

#ifdef STANDALONE_LEXER
int main() {
    yylex();
    return 0;
}
#endif