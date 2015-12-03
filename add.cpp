#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<wait.h>

using namespace std;

int main(int argc,char **argv)
{
 int returnval,n;
 pid_t p;

 n=atoi(argv[argc-1]);

 n=(n*2);   
 sprintf(argv[argc-1],"%d",n);                   //Double
 p=fork();
 if(p==0)
 {
   printf("The PID of double is:%d\n,The PPID double is:%d\n",getpid(),getppid());  
   if(argc>2)
   {
     execv(argv[1],&argv[1]);
   }
   
   exit(2);
 }
 else 
 {
  printf("The PID double is:%d\n,The PPID of double is:%d\n",getpid(),getppid());
  wait(&returnval);
 if(argc==2)
   cout<<"Result1:"<<n<<endl;  
 }
 return 0;
}
