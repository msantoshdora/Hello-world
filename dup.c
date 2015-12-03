#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#define MODE600 (S_IRUSR,S_IWUSR)
int main(int argc,char **argv)
{ 
 int fd1,fd2;
 fd1=open(argv[1],O_RDONLY);
 fd2=open(argv[2],O_WRONLY|O_CREAT | O_TRUNC,MODE600);
  close(STDIN_FILENO);
  dup(fd1);
 close(STDOUT_FILENO);
 dup(fd2);

 execvp(argv[3],&argv[3]);
 
 
 return 0;
}
