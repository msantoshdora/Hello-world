#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<cstring>
#include<climits>
#include<ctime>
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int maximum(const int a[],int left,int right);
int process(const int a[],int left,int right);

int maximum(const int a[],int left,int right)
{
 int max=INT_MIN;
 int i;
 for( i=left;i<right;i++)
 {
    if(max<a[i])
    {
       max=a[i];
    }
 }
//cout<<"max"<<max<<endl;
 return max;
}



int  process( const int a[],int left,int right)
{
 int m,mid,m1,m2,v;
 pid_t pid1,pid2;
 if((right-left)<9)
 {
  return( maximum(a,left,right));
 }
else
{
 mid=(left+right)/2;
 
if((pid1=fork())==0)
{
 /* Child1 Process*/
 printf("The PID of child1:%d\n,The PPID of child1:%d\n",getpid(),getppid());
  m1=process(a,left,mid);
                            // cout<<"m1:"<<m1<<endl;

  exit(m1);  
}
else if((pid2=fork())==0)
{
/*child2 Process*/
printf("The PID of child2:%d\n,The PPID of child2:%d\n",getpid(),getppid());
  m2=process(a,mid+1,right);
 
  exit(m2);
}
else
{
   /*Parent Process*/
 printf("The PID of Parent:%d\n,The PPID of Parent:%d\n",getpid(),getppid()); 
 int fc,sc,f,c;
 waitpid(pid1,&fc,0);
 waitpid(pid2,&sc,0);
//cout<<"fc:"<<(fc>>8)<<endl;
//cout<<"sc:"<<(sc>>8)<<endl;
f=fc >> 8;
c= sc >> 8;
 if(f>c)
  return f;
 else
  return c;
}
  
}
//  return m;
}


int main(int argc,char **argv)
{
 pid_t pr;
 int i,m;
 int n=atoi(argv[1]);
 int a[n]; 
 //cout<<"Being here\n";
 for(i=0;i<n;i++)
 { 
// cout<<"I am inserting\n";
    srand(i);
    a[i]=rand()%128;
 //  cout<<"a[]"<<i<<" "<<a[i]<<endl;  
 }

 //the array is
 
for(int j=0;j<n;j++)
{
  cout<<a[j]<<"->";
}
cout<<endl;
pr=fork();
if(pr==0)
{
 printf("The PID of initial child:%d\n,The PPID of initial child:%d\n",getpid(),getppid());
 exit(process(a,0,n));
}
else
{
 printf("The PID of initail child:%d\n,The PPID of initial child:%d\n",getpid(),getppid());
 wait(&m);
 i = m >> 8;
}
 printf("The maximum element is: %ld\n",i);
 return 0;
}
