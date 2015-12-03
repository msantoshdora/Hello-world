%{#include<stdio.h>

  int c=0,i;
%}

%%

"//"[a-zA-Z0-9\t] {c++;}

%%

int main(int argc,char *argv[])
{
 yyin=fopen(argv[1],"r");
 yylex();
 printf("No. of single line comments:%d\n",c);
 fclose(yyin);

return 0;
}
int yywrap()
{
return 1;
}



