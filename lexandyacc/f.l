%{
    int line_no=0;
%}
%%
^(.*)\n printf("%4d\t%s",++line_no,yytext);
%%


int main(int argc,char *argv[])
{
 // FILE *yyin;
  yyin=fopen(argv[1],"r");
  yylex();
  fclose(yyin);
  return 0;
}

int yywrap(void)
{
  return 1;
}
