%{
#include<stdio.h>
#include "2b.tab.h"
extern int yylval;
%}
%%
[\t] ;
[+|-|*|\|=] {printf("operator is %c\n",yytext[0]); return OP;}
int|main|if|printf|for|return|else {printf("keyword is %s\n",yytext); return KEY;}
[_a-zA-Z][0-9A-Z]* {printf("identifier is %s\n",yytext); return ID;}
[0-9][a-z][0-9a-z]* ;
"(".*");" ;
. ;
%%
