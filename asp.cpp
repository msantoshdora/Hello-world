#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
 long long int n,t1=0,t2=0,m,a,b,c,k=0,l=0;
scanf("%lld",&n);
long long int ar,br;
for(long long int i=0;i<n;i++)
{
 scanf("%lld",&a);
 if(i%2==0)
 {
  if(a<ar && k!=0)
  {
    t1=-1;
  //  break;
  }
 ar=a;
 k=2;
 }
 else
 {
  if(a<br && l!=0 )
  {
   t2=-1;
  }
 br=a;
 l=2;
 }
 
}
if(t1==-1 || t2==-1)
{
 printf("NO\n");

}
else
{
printf("YES\n");
}

}
return 0;
}
