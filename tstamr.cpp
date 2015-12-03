#include<iostream>
#include<stdio.h>
#include<algorithm>
#define BS 101
using namespace std;
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int a[BS];
  int s;
  scanf("%d",&s);
  for(int i=0;i<s;i++)
  {
    scanf("%d",&a[i]);
  }
  sort(a,a+s);
  for(int i=0;i<s-1;i++)
  {
    if(a[i]==a[i+1])
    {
      cout<<"NO\n";
      s=-1;
     break;
    }
  }
  if(s!=-1)
  {
    cout<<"YES\n";
  }
 
 }
 return 0;
}
