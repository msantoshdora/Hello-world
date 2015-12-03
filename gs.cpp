#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  string S;
  char a[30]={0};
  cin>>S;
  int j=0;
  a[j]=S[0];
  for(int i=1;i<S.length();i++)
  {
   if(a[j]!=S[i])
   {
     j++;
    a[j]=S[i];
    
   }
  }
  for(int i=0;i<=j;i++)
  {
    cout<<a[i];
  }
 cout<<endl;
 }
return 0;
}
