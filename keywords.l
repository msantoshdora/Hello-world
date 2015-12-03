keyword main|if|else|do|while
%{
 #include<stdio.h>
 int i=0;
%}
%%
{keyword} {for(i=0;i<yyleng;i++)
           fprintf(yyout,"%c",yytext[i]);}
[a-zA-Z]+ {for(i=0;i<yyleng;i++)
             fprintf(yyout,"%c",toupper(yytext[i])); }                     
           
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
