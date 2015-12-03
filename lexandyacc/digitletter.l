%{
 int count=0;
%}

 
 
%%
[A-Za-z]([A-Za-z]|[A-Za-z])*  count++;

%%

int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
printf("No. of letters%d\n",count);
fclose(yyin);

return 0;
}

int yywrap()
{
return 1;
}
