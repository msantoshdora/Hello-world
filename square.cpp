#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<bits/stdc++.h>
using namespace std;

int main(int argc,char **argv)
{
 int n,r;
 pid_t p;
 n=atoi(argv[argc-1]);
 n=n*n;
// itoa(n,argv[argc-1],10);
 sprintf(argv[argc-1],"%d",n);

 p=fork();
 if(p==0)
 {
   printf("The PID of square is:%d\n,The PPID of square is:%d\n",getpid(),getppid());
   if(argc>2)
   {
     execv(argv[1],&argv[1]);
   }
   exit(4);
 }
 else
 {
   waitpid(p,&r,0);
   printf("The PID of square is:%d\n,The PPID of parent square is:%d\n",getpid(),getppid());
   if(argc==2)
   {
     cout<<"Result:"<<n<<endl;
   }
  
 }
return 0;
}
