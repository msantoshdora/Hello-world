word [a-zA-Z]+
%{
int w=0,ln=0,lten=0,i;
%}
%%
{word} {w++;if(yyleng>9)lten++;}
"\n" {ln++;}

%%
int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
printf("Words:%d\n",w);
printf("Lines:%d\n",ln);
printf("words 10:%d\n",lten);
return 0;
}
int yywrap()
{
return 1;
}
