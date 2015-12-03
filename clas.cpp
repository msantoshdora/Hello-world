#include<iostream>
using namespace std;

class cvector
{
 int xa,ya;
 public:
     cvector()
     {
         xa=0;
         ya=0;
     }
    cvector(int a,int b)
    {
       xa=a;
       ya=b;
    }
     cvector operator+(const cvector& );
     void operator++(int);
     void operator++();
     friend ostream& operator<<(ostream& cv,cvector tr);
};
void cvector::operator++(int)
{
  
  xa++;
  ya++;
}

void cvector::operator++()
{
 xa++;
 ya++;
}
ostream& operator<<(ostream& cv,cvector tr)
{
 cv<<tr.xa;
 cv<<" ";
 cv<<tr.ya;
 return cv;
}
cvector cvector::operator+(const cvector& p)
{
 cvector a;
 a.xa=xa+p.xa;
 a.ya=ya+p.ya;

 return a;
}

int main()
{
 //cvector c,d,res;
 int v1,v2;
 cout<<"Enter the first vectors\n";
 cin>>v1>>v2;
 cvector c(v1,v2); 
 cout<<"Enter the second vector\n";
 cin>>v1>>v2;
 cvector d(v1,v2);
cvector res;
 res=c+d;
 cout<<res;
 return 0;
}
