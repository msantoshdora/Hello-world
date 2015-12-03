#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int findLength(string &a)
{
 int size=0;
 while(a[size]!='\0')
 {
  // cout<<"size->"<<size;
   ++size;
 }

 return size;
}

int main()
{
 string s;
 cout<<"Enter the string literal\n";
 cin>>s;
 cout<<"SIZE is: "<<findLength(s);
 return 0;
}
