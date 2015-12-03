#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
 int n;
 cin>>n;
 
while(n--)
{
 string S;
 cin>>S;
 char first=S[0];
 long long int del=0,j;
 for(long long int i=1;i<S.length();i++)
 {
  if(S[i]==first)
   {
     del++;
   }
   else
   {
    first=S[i];
   }
 }
 cout<<del<<endl;
}
 return 0;
}
