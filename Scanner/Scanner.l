%{
#include <stdio.h>
#include <stdlib.h>
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
"bool"          { return BOOL_TYPE; }
"char"          { return CHAR_TYPE; }
"int"           { return INT_TYPE; }
"real"          { return REAL_TYPE; }
"string"        { return STRING_TYPE; }
"int*"          { return INTPTR_TYPE; }
"char*"         { return CHARPTR_TYPE; }
"real*"         { return REALPTR_TYPE; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"var"           { return VAR; }
"func"          { return FUNC; }
"proc"          { return PROC; }
"return"        { return RETURN; }
"null"          { return NULL_PTR; }

/* --- ליטרלים (Literals) --- */

/* בוליאני */
"true"|"false"  { return BOOL_LITERAL; }

/* מספרים שלמים: עשרוני (לא מתחיל ב-0 אלא אם הוא רק 0) או הקסדצימלי */
0|[1-9]{DIGIT}* { return INT_LITERAL; }
0[xX]{HEX}+     { return HEX_LITERAL; }

/* מספרים ממשיים: תומך בנקודה עשרונית ובכתיב מדעי עם E/e, וגם סימני +/- */
[-+]?([0-9]+\.[0-9]*|\.[0-9]+)([eE][-+]?[0-9]+)?|[-+]?[0-9]+[eE][-+]?[0-9]+ { return REAL_LITERAL; }

/* מחרוזות: מוקפות במרכאות כפולות, לא נשברות שורה, ותומכות בתווי Escape */
\"([^\"\n\\]|\\.)*\" { return STRING_LITERAL; }

/* תווים (char): מוקפים בגרש בודד, תומכים בתווי Escape */
\'([^'\n\\]|\\.)\'   { return CHAR_LITERAL; }

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