%{
int a=0,b=0,c=0,d=0,e=0,f=0,fa=0,fb=0,fc=0,fd=0,fe=0,i;
%}
%%
[a-zA-Z]+[+-/^*]?[=][a-zA-Z]+([+-/^*][a-zA-Z]+)*[;] {printf("valid\n");for(i=0;i<yyleng;i++){if(yytext[i]=='+')a++;if(yytext[i]=='-')b++;if(yytext[i]=='/')c++;if(yytext[i]=='*')d++;if(yytext[i]=='^')f++;}}
[a-zA-Z]+ printf("%s identifier",yytext);
%%

int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
if(a!=0)
{
printf("addition:%d\n",a);
}
if(b!=0)
{
printf("subtraction:%d\n",b);
}
if(c!=0)
{
printf("Division:%d\n",c);
}
if(d!=0)
{
printf("Multiplication:%d\n",d);
}
if(f!=0)
{
printf("^:%d\n",f);
}

return 0;
}

int yywrap()
{
return 1;
}


