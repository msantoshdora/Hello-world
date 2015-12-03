%{
int cc=0;
%}
%%
"//"[^\t\n]+ cc++;
%%
int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
printf("Line of comments:%d\n",cc);
return 0;
}
int yywrap()
{return 1;
}
