#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{
 char **ch;
 //int l=strlen(ch);
//cout<<"Hi";
ch=new char*[10]; 
for(int i=0;i<10;i++)
 {
  // cout<<"Hello\n";
	  ch[i]=new char[10];
  // cout<<"bye";
   cin>>ch[i];
 }

//cout<<"Hi\n";
for(int i=0;i<10;i++)
 {
  cout<<ch[i]<<" ";
 }
 return 0;
}
