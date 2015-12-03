%{
int i;
int c=0;
%}
%%
"/*"[^.\t\n]* {for(i=0;i<yyleng;i++)if(yytext[i]=='\n')c++;c++;}
[^.\t\n]*"*/"  c++;
"//"[^.\t\n]* c++;
 
%%
int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
printf("lines:%d\n",c);
return 0;
}
int yywrap()
{

return 1;
}
