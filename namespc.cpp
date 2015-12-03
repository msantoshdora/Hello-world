#include<iostream>
using namespace std;
namespace first
{
 int x=5;
}

namespace second
{
 
int x=2;
 int y=3;
}

int main()
{
cout<<second::x<<endl;
cout<<second::y<<endl;

using namespace second;
cout<<x<<endl;
cout<<y<<endl;
cout<<first::x<<endl;
 return 0;
}
