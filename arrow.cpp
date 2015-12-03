#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int x,temp=0,e;
  cin>>x;
  e=0;
  int a[x];
  int b[x];
   for(int i=0;i<x;i++)
   {
    a[i]=5;
    b[i]=3;
   }
  if(x%3==0 || x%15==0)
  {
   while(x--)
   {
    cout<<"5";
   }
   cout<<endl;
  }
 else
 {
  if(x%5==2 || x==1 || x==2 || x==4)
  {
   cout<<"-1"<<endl;
  }
  else
  {
   int  fr=x;
    while(x>0)
    {
      int ch=0;
      int mod=x%5;
      if(mod==0)
      {
        break;
      }
      while(mod>0 || ch%3!=0 && e<fr)
      {
       b[e]=5;
       e++;
       mod--;
       ch++;  
      }
     x=x-ch;
      
    }
   for(int i=0;i<fr;i++)
   {
    cout<<b[i];
   } 
   cout<<endl;
  }
 
 }
 }
 return 0;
}
