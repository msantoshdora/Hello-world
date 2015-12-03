vowels [aeiouAEIOU]
%{
int c=0;
%}
%%
{vowels}+ c++;
. {}
%%
int main(int argc,char *argv[])
{
 yyin=fopen(argv[1],"r");
 yylex();
printf("%d\n",c);
return 0;
}
int yywrap()
{
 return 1;
}

