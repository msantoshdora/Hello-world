#include<iostream>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>

using namespace std;

int main(int argc,char **argv)
{
 int n,returnval;
 pid_t p;
 n=atoi(argv[argc-1]);
 n=(n/2);
sprintf(argv[argc-1],"%d",n);
 p=fork();
 if(p==0)
 {
   printf("The PID of half is:%d\n,The PPID of half is:%d\n",getpid(),getppid());
   if(argc>2)
   {
    execv(argv[1],&argv[1]);
   }
   exit(2);
 }
 else
 {
  
  waitpid(-1,&returnval,0);
  printf("The PID parent half is:%d\n,The PPID parent half is:%d\n",getpid(),getppid());
  if(argc==2)
   cout<<"Result:"<<n<<endl;
  
 }
 return 0;
}
