%{
    #include<stdio.h>
    int v=0,op=0,id=0,flag=0;
%}

%%
[0-9]+ {id++;}
[+*/-] {op++;}
\( {v++;} 
\) {v--;}
\n {return 0;}
%%

int yywrap() { return 1; }
int main()
{
    printf("Enter the expression:"); 
    yylex();
    if((op+1)==id && v==0) {
        printf("\nExpression is Valid\n");
        printf("No of identifier = %d \nNo of Operators = %d \n", id, op);
    } else
        printf("\n Expression is Invalid\n");

    return 0;
}