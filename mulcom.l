%{
  int i;
  int nl=0;
  int nc=0;
%}
%%
"/*"[^.\n]*"*/" {for(i=0;i<yyleng;i++)if(yytext[i]=='\n')nl++;nc++;}
"//"[^.\n] nl++;
%%
int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
printf("NUMBER OF SINGLE LINE COMMENT:%d\n No. MULTICOMMENT:%d\n",nl,nc);
return 0;
}
int yywrap()
{
 return 1;
}
