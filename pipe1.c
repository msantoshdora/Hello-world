#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
 int fd[2];
 char input[30]="Santosh Hello";
 char output[30];
 //pipe(fd);
 if(!pipe(fd))
 {
   printf("Inside the Pipe\n");
  //close(fd[0]);
  open(fd[1]);
  //close(fd[0]);
  write(fd[1],input,strlen(input)+1);
  open(fd[0]);
  close(fd[1]);
  //open(fd[0]);
  read(fd[0],output,30);
  printf("\nRead: %s\n",output);
  close(fd[0]);
 }
 else
 {
  printf("Error\n");
 }
 return 0;
}
