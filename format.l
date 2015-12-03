%{
int a=0,b=0,c,i;
%}
%%
[\n] {a++;b++;c=0;fprintf(yyout,"\n");}
[ ]  {if(c>0 && c<70)fprintf(yyout," ");c++}
[^\t\n ]+ {if(c>0 && (c+yyleng)>70){fprintf(yyout,"\n%s",yytext);c=yyleng;}else{fprintf(yyout,"%s",yytext);c=c+yyleng;a++;}}
%%
int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yyout=fopen(argv[2],"w");
yylex();
printf("Number of lines before formatting:%d\n",b);
printf("Nmber of lines after formatting:%d\n",a);
return 0;
}
int yywrap()
{
return 1;
}

