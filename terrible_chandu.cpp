#include<iostream>
#include<string>
#include<cstring>
#include<ctype.h>
#include<stdio.h>
using namespace std;

int main()
{
	int t;
 	cin>>t;
        char ch;
       ch=getchar();
 	while(t--)
 	{
  	 string str;
  	 //cin>>str;
  	 getline(cin,str);
	  int len;
          len=str.size();
         //cout<<"size"<<len;
         for(int i=len-1;i>=0;i--)
          { cout<<str[i];
          }
         cout<<endl;
 	}
 return 0;
}
