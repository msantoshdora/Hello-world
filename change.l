%{
int i=0;
%}
%%
"printf" {fprintf(yyout,"writef");}
"scanf"  {fprintf(yyout,"readf");} 
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
