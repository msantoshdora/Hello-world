#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#define BS 30
 
char buf[BS]="foo";
//buf[BS]="foo.c";

void alrm_handler(int signo)
{
  signal(SIGALRM,alrm_handler);
  printf("Error Code: %d, file name default: %s ",signo,buf);
  exit(1);
}
int main()
{
 int n;
 
 if(signal(SIGALRM,alrm_handler)==SIG_ERR)
 {
  printf("Error\n");
  exit(0);    
 }
 printf("Enter the file name\n");
 alarm(5);   //Wait for 5 seconds
 n=read(STDIN_FILENO,buf,BS);
 if(n>1)
 {
  printf("File name is:%s\n",buf);
 }
 
 return 0;
}
