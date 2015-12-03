#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<wait.h>
using namespace std;

int main(int argc,char *argv[])
{
 int returnval;
 pid_t p;
 p=fork();
 if(p==0)
 {
   if(argc>1)
   {
     execv(argv[1],&argv[1]);
   }
   else
   {
    cout<<"No operations specified \n";
   }
  fprintf(stderr,"execv error\n");
  exit(200);
 }
 else
 {
    wait(&returnval);
    fprintf(stderr,"Exit Status:%d\n",WEXITSTATUS(returnval));
    exit(0);
 } 
 return 0;
}
