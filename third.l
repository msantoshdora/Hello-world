%{
int count;
%}
%%
.|\n  {count++;}
%%

int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
printf("Number of identifier is:%d\n",count);

}

int yywrap()
{
return 1;
}

