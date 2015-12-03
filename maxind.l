%{
int l[1000]={0},i,max=0,ln=0;
%}
%%
"\n" ln++;
" "*  {l[ln]=l[ln]+1;}
. {}
%%
int main(int argc,char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
for(i=0;i<ln;i++)
{
if(max<l[i])
  max=l[i];
}
printf("max is:%d",max);
return 0;
}
int yywrap()
{
return 1;
}

