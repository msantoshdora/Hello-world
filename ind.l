%{
 #include<stdio.h>
 int a[100]={0};
 int lineno=0;
 int max=0;
 int i;
%}
%%
[\n] lineno++;
[\t] {a[lineno]=a[lineno]+1;}
. {}
%%
int main(int argc,char *argv[])
{
 yyin=fopen(argv[1],"r");
yylex();
 for(i=0;i<lineno;i++)
 {
   if(max<a[i])
     max=a[i];  
 }
printf("Max indentation is:%d\n",max);
return 0;
}
int yywrap()
{
return 1;
}
