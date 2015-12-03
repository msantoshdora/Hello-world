keywords main|int|do|double|while|long|return|include|void|float|char|if|else
spl [:;'".</?|\}{0(*&%#!]
%{
int i;
%}
%%
{keywords}+ {for(i=0;i<yyleng;i++)fprintf(yyout,"%c",yytext[i]);}
{spl}+ {fprintf(yyout," ");}
[\n\t ] fprintf(yyout,yytext);
. {fprintf(yyout,"%c",toupper(yytext));}
%%

int main(int argc,char*argv[])
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

