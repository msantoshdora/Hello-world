keywords main|if|else|int|float|char|do|while|include
%{
int i;
int c=0;
%}
%%
{keywords}+ {for(i=0;i<yyleng;i++)fprintf(yyout,"%c",toupper(yytext[i]));c++;} 
%%
int main(int argc,char *argv[])
{
 yyin=fopen(argv[1],"r");
 yyout=fopen(argv[2],"w");
 yylex();
 printf("%d",c);
 return 0;
}
int yywrap()
{
return 1;
}
 
