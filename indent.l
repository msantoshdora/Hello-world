%{
int c=0,i;
%}
%%
"{" {c++;fprintf(yyout,"{");}
"\n}" {c--;fprintf(yyout,"\n");for(i=0;i<c;i++)fprintf(yyout,"\t");fprintf(yyout,"}");}
"\n" {fprintf(yyout,"\n");for(i=0;i<c;i++)fprintf(yyout,"\t");}
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
