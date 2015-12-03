#include<iostream>
using namespace std;

int check(int a)
{
 return((a>0)&&(a&(a-1))==0);
}
int main()
{
int v;
cout<<"Enter the number\n";
cin>>v;

if(check(v))
 cout<<"YES power of 2\n";
else
 cout<<"Not a power of 2\n";
return 0;
}
