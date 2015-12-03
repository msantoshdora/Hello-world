#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

int main()
{
 srand(234);
 cout<<"Required:"<<rand()<<endl;
 srand(2311);
 cout<<"Required:"<<rand()<<endl;
 srand(234);
 cout<<"Required:"<<rand()<<endl;
 srand(1);
 cout<<"Required:"<<rand()<<endl;

return 0;
}
