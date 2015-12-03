%{#include<stdio.h>
  int c=0,i;
%}

%%

"//"[a-zA-Z0-9\t ]* {c++;}

"/*"[a-zA-Z0-9\n\t]*"*/"  {for(i=0;i<yyleng;i++)if(yytext[i]=='\n')c++;  c++;}

%%

int main(int argc,char *argv[])
{
  yyin=fopen(argv[1],"r");
  yylex();
  printf("No. of multi line comments: %d\n",c);
  fclose(yyin);
 return 0;
}

int yywrap()
{
return 1;
}
