%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* חיבור היאק בהמשך */
int line_number = 1;
/* משתנה גלובלי למען מעקב אחרי מספרי שורות ( זה עוזר להודעות שגיאה אבל לא בטוח נצטרך את זה  אבל שיהיה) */

%}

/* הגדרות של פלקס - noyywrap אומר פשוט מתי שסתיים לקרוא את הקובץ תעצור */
%option noyywrap

/* מצב התחלה בלעדי עבור הערות בלוק */
/* בקצרה זה יוצר "מצב" חדש לאוטומט בשם COMMENT וברגע שהלקס יכנס אליו הוא ויתייחס רק לחוקים ששייכים להערות */
%x COMMENT 

/* --- ביטויים רגולריים בסיסיים לעזר --- */
ALPHA      [a-zA-Z]
DIGIT      [0-9]
HEX        [0-9a-fA-F]

%%

/* --- טיפול בהערות --- */

/*        המבנה תמיד יהיה זהה מצד שמאל ביטוי רגולרי מצד ימין הפעולה בשפת סיי */

"/%"            { BEGIN(COMMENT); } 
<COMMENT>\n     { line_number++; }  
<COMMENT>.      { /* בולעים תווים */ }
<COMMENT>"%/"   { BEGIN(INITIAL); }

/* --- התעלמות מרווחים וירידות שורה --- */
[ \t\r]+        { /* מתעלמים מרווחים וטאבים */ }
\n              { line_number++; }

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
"null"          { return NULL; }


/* --- ליטרלים (Literals) --- */

/* בוליאני */
"true"          { return TRUE_LITERAL; }
"false"         { return FALSE_LITERAL; }


/* מספרים שלמים: עשרוני (לא מתחיל ב-0 אלא אם הוא רק 0) או הקסדצימלי */
0|[1-9]{DIGIT}* { 
    yylval.int_val = atoi(yytext);    
    return INT_LITERAL;
}

0[xX]{HEX}+     { 
    yylval.int_val = strtol(yytext + 2, NULL, 16);
    
    return HEX_LITERAL; 
}
/* מספרים ממשיים: תומך בנקודה עשרונית ובכתיב מדעי עם E/e, וגם סימני +/- */
[-+]?([0-9]+\.[0-9]*|\.[0-9]+)([eE][-+]?[0-9]+)?|[-+]?[0-9]+[eE][-+]?[0-9]+ { 

    yylval.real_val = atof(yytext);    
    return REAL_LITERAL; }

/* מחרוזות: מוקפות במרכאות כפולות, לא נשברות שורה, ותומכות בתווי Escape */
\"([^\"\n\\]|\\.)*\" { 
    int len = yyleng - 2;
    char* str = (char*)malloc(len + 1);
    strncpy(str, yytext + 1, len);
    str[len] = '\0';
    yylval.str_val = str;
    return STRING_LITERAL; 
}

/* תווים (char): מוקפים בגרש בודד, תומכים בתווי Escape */
\'([^'\n\\]|\\.)\'   { 
    if(yytext[1] != '\\')
        yylval.char_val = yytext[1];
    else{
        switch(yytext[2]){
            case 'n' : yylval.char_val = '\n';
            case 't': yylval.char_val = '\t'; break;
            case 'r': yylval.char_val = '\r'; break;
            case '\\': yylval.char_val = '\\'; break;
            case '\'': yylval.char_val = '\''; break;
            default:  yylval.char_val = yytext[2]; break; 
        }
    }
    return CHAR_LITERAL;

 }

/* מזהים (Identifiers): מתחיל באות, ואז אותיות, ספרות או קו תחתון */
{ALPHA}({ALPHA}|{DIGIT}|"_")* { return IDENTIFIER; }

/* --- אופרטורים ותווים מיוחדים --- */
"=="            { return EQ; }
"!="            { return NEQ; }
">="            { return GTE; }
"<="            { return LTE; }
"&&"            { return AND; }
"||"            { return OR; }


/* תווים בודדים אפשר להחזיר ישירות ל-Yacc בתור קוד ה-ASCII שלהם */
"+"|"-"|"*"|"/"|">"|"<"|"!"|"="|"^"|"&"|"|"|";"|":"|","|"["|"]"|"{"|"}"|"("|")" 
{ 
    return yytext[0]; 
}

/* --- שגיאות לקסיקליות --- */
.               
{ 
    printf("Lexical Error on line %d: Unrecognized character '%s'\n", line_number, yytext); 
    exit(1); 
}

%%

int yywrap(){
    return 1;
}