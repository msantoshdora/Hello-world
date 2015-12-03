#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[10];
int x[10]={0};
int m;
void sumofsubset(int sum,int k,int rem)
{
  x[k]=1;
if(sum+a[k]==m)
 {
   cout<<"Required subset: ";

   cout<<"{";
   for(int i=0;i<=k;i++)
   {
     if(x[i]==1)
      cout<<a[i]<<",";
     
   }
   cout<<" }\n";
 }
else{
 if((sum + a[k] +a[k+1]<=m) )
{ 
  sumofsubset(sum+a[k],k+1,rem-a[k]);
}
}
 if(((sum+rem-a[k]) >=m)&&((sum + a[k+1])<=m) )
 {
   x[k]=0;
   sumofsubset(sum,k+1,rem-a[k]);
 } 
}

int main()
{
int r=0;
 cout<<"Enter 10 elements \n";
 for(int i=0;i<10;i++)
 {
   cin>>a[i];
   r=r+a[i];
 }
cout<<"Enter required sum\n";
cin>>m;
sort(a,a+10);
 sumofsubset(0,0,r-a[0]);
return 0;
}
