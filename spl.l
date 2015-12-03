spl [;".|,<%#<>{}\/?!*i)()]
%{
 #include<stdio.h>
 int i;
%}
%%
{spl}+ {fprintf(yyout," ");}
.   {fprintf(yyout,"%c",yytext[i]);}
%%
int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yyout=fopen(argv[2],"w");
yylex();
return 0;
}
int yywrap()
{
 return 1;
}
