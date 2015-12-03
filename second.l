%{
int yylinen=0;
%}
%%
^(.*)\n {yylinen++;printf("The line no. is: %d\n The text is:%s\n",yylinen,yytext);}
%%

int yywrap()
{
 return 1;
}
int main(int argc,char *argv[])
{
 yyin=fopen(argv[1],"r");
 yylex();
 return 0;
}
