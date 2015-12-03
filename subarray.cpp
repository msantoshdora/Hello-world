#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
 long long int n,x,j,k,s;
 cin>>n;
 cin>>x;
 long long int cost[n];
 for(long long int i=0;i<n;i++)
  cin>>cost[i];
 j=0;
 k=0;
 s=0;
 while(s!=x && j<n)
 {
  while(s>x)
  {
   s=s-cost[k++];
   if(s==x)
    break;
  }
  
   s=s+cost[j];
  j++;
// cout<<"SUM is="<<s<<endl;
 }
//cout<<"s="<<s<<"X="<<x;
while(s>x)
{
 s=s-cost[k++];
}
if(s==x)
{
 cout<<"YES"<<endl;
}
else
 cout<<"NO"<<endl;
 
 
 }
 return 0;
}
