#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
long long int t;
 cin>>t;
 while(t--)
 {
 long long int n1,n2,m,i,sum=0;
  cin>>n1>>n2>>m;
 
  i=1;
  while(n1>0 && n2>0 && i<=m && i<=n1 && i<=n2)
  {
   n1=n1-i;
   n2=n2-i;
   i++;
  }
  cout<<n1<<" "<<n2<<endl; 
sum=n1+n2;
  cout<<sum<<endl;
 }
 return 0;
}
