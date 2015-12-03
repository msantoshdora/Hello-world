%{
 int c=0;
%}
%%
[aeiouAeiou]+ c++;
. 
%%
int main()
{
yylex();
printf("VOWELS:%d\n",c);
return 0;
}
int yywrap()
{return 1;
}
