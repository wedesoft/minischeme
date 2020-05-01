%{

#include <stdio.h>
#include "lexer.h"

YYSTYPE yylval;

%}

%option noyywrap
%option always-interactive

%%

[0-9]+    { yylval.number = atoi(yytext); return NUMBER; }
[^\t\r\n] { yylval.symbol = yytext; return SYMBOL; }
[ \t\r\n] ;

%%
