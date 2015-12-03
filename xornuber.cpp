#include<iostream>
using namespace std;

int main()
{
 int a,t;
cin>>t;
while(t--)
{
 cin>>a;
 int b=a^(a+1);
  cout<<b<<endl;
}
return 0;
}
