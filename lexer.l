%option noyywrap nodefault yylineno case-insensitive
%{
#include "ast.h"
#include "parser.tab.h"
#include <stdarg.h>
#include <string.h>

void yyerror(char *s, ...);
int oldstate;

%}
%x COMMENT
%s BTWMODE

%%

    /* BETWEEN ... AND ...的特殊处理 */
<BTWMODE>AND { BEGIN INITIAL; return AND; }
AND { return ANDOP; }
AS { return AS; }
ASC { return ASC; }
BY { return BY; }
CASE { return CASE; }
COUNT { return COUNT; }
DELETE { return DELETE; }
DESC { return DESC; }
ELSE { return ELSE; }
END { return END; }
EXIT { return EXIT; }
FROM { return FROM; }
GROUP { return GROUP; }
IN { return IN; }
INSERT { return INSERT; }
INTO { return INTO; }
LIKE { return LIKE; }
LIMIT { return LIMIT; }
NOT { return NOT; }
OR { return OR; }
ORDER { return ORDER; }
SELECT { return SELECT; }
SET { return SET; }
SUM { return SUM; }
THEN { return THEN; }
UPDATE { return UPDATE; }
VALUES { return VALUES; }
WHEN { return WHEN; }
WHERE { return WHERE; }

    /* 数字 */
-?[0-9]+ { yylval.intval=atoi(yytext); return INTNUM; }
-?[0-9]+"."[0-9]* |
-?"."[0-9]+ |
-?[0-9]+E[-+]?[0-9]+ |
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]+E[-+]?[0-9]+ { yylval.floatval=atof(yytext); return APPROXNUM; }

    /* 字符串 */
'(\\.|''|[^'\n])*' |
\"(\\.|\"\"|[^"\n])*\" { yylval.strval = strdup(yytext); return STRING; }

'(\\.|[^'\n])*$ { yyerror("Unterminated string %s", yytext); }
\"(\\.|[^"\n])*$ { yyerror("Unterminated string %s", yytext); }

    /* 十六进制字符串 */
X'[0-9A-F]+' |
0X[0-9A-F]+ { yylval.strval = strdup(yytext); return STRING; }

    /* 二进制字符串 */
0B[01]+ |
B'[01]+' { yylval.strval=strdup(yytext); return STRING; }

    /* 操作符 */
[-+&~|^/%*(),.;!] {return yytext[0]; }

"&&" { return ANDOP; }
"||" { return OR; }

"=" { yylval.subtok=EXPR_EQ; return COMPARISON; }
">=" { yylval.subtok=EXPR_GE; return COMPARISON; }
">" { yylval.subtok=EXPR_GT; return COMPARISON; }
"<=" { yylval.subtok=EXPR_LE; return COMPARISON; }
"<" { yylval.subtok=EXPR_LT; return COMPARISON; }
"!=" |
"<>" { yylval.subtok=EXPR_NE; return COMPARISON; }

    /* check trailing context manually */
COUNT { int c=input(); unput(c);
        if(c=='(') return FCOUNT;
        yylval.strval=strdup(yytext); return NAME; }

SUM { int c=input(); unput(c);
        if(c=='(') return FSUM;
        yylval.strval=strdup(yytext); return NAME; }

    /* 名字 */
[A-Za-z][A-Za-z0-9_]* { yylval.strval = strdup(yytext); return NAME; }
`[^`/\\.\n]+` { 
    yylval.strval=strdup(yytext+1);
    yylval.strval[yyleng-2]=0;
    return NAME;
    }

`[^`\n]*$ { yyerror("Unterminated quoted name %s",yytext); }

    /* 注释 */
#.* ;
"--"[ \t].* ;

    /* Others */
[ \t\n] 
. { yyerror("Mystery character '%c'", *yytext); }

%%

// main(int argc, char *argv[])
// {
//     int tok;
//     while(tok=yylex()) {
//         printf("tok : %d\n", tok);
//         if(tok==INTNUM) printf("INTNUM = %d\n", yylval.intval);
//         else if(tok==APPROXNUM) printf("APPROXNUM = %f\n", yylval.floatval);
//         else if(tok==NAME) printf("NAME : %s\n", yylval.strval);
//         else printf("OTHERS : %s\n", yylval.name);
//     }
// }