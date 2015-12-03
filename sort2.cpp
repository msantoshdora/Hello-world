#include<iostream>
//#include<algorithm>
using namespace std;
struct node
{
 int p;
 int q;
};


struct node a[1000],b[1000];



void sort(int k,int key)
{
    int t;
    if(key==1){
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<4;j++)
        {
          if(a[j].p >a[j+1].p)
          {
             t=a[j].p;
             a[j].p=a[j+1].p;
              a[j+1].p=t;
              t=a[j].q;
              a[j].q=a[j+1].q;
              a[j+1].q=t;    
          }
        }
    }
}
else
{
 for(int i=0;i<k;i++)
 {
          for(int j=0;j<4;j++)
          {
            if(b[j].p >b[j+1].p)
            {
               t=b[j].p;
               b[j].p=b[j+1].p;
                b[j+1].p=t;
                t=b[j].q;
                b[j].q=b[j+1].q;
                b[j+1].q=t;
           }
         }
     }
}
 //return ar;
}
int main()
{
// struct node a[5];
 char c;
 int f=0,se=0,n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
    
   if(c=='S')
   {
    f++;
   cout<<"\nValue of p:\n";
   cin>>a[i].p;
   cout<<"\n Value of q:\n";
   cin>>a[i].q;
   }
   else
   {
    se++;
        cin>>b[i].p;
        cin>>b[i].q;
   }
 }
sort(f,1);
sort(se,0);
//for(int i=0;i<5;i++)
//{
 // cout<<a[i].p<<":";
 // cout<<a[i].q<<"|\n";
//}
for(int i=0;i<5;i++)
{
  if(a[i].p==a[i+1].p)
  {
       a[i+1].q=a[i+1].q+a[i].q;
       a[i].p=-1;
  }
}
sort();
for(int i=0;i<5;i++)
{
 
    cout<<a[i].p<<":";
    cout<<a[i].q<<"|";
   cout<<endl;
}
return 0;
}
