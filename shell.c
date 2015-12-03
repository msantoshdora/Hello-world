
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>
#include<string.h>
#define delim "\n\t\r "

int main()
{
 int n,r,i;
 char buff[200];    //Command
 char *arg[40];     //Tokens in command
 pid_t f;

 while(1)
 {
  n=1; 
 for(i=0;i<200;i++)
   buff[i]='\0';

 for(i=0;i<40;i++)
   arg[i]='\0';

   printf("SHELL> ");
   gets(buff);
   //write(STDOUT_FILENO,"SHELL> ",7);
  // read(STDIN_FILENO,buff,200);
   if(!(strcmp(buff,"exit")))
      exit(0);
   //scanf("%s",&buff);
  // printf("%s\n",buff);
   arg[0]=strtok(buff,delim);
   while(arg[n]=strtok(NULL,delim))
       n++;

   f=fork();
   if(f==0)
   {
      execvp(arg[0],&arg[0]);
      exit(200);
   }
   else
   {
    wait(&r);
    printf("The exit status:%d\n",WEXITSTATUS(r));
   }
 // break;
 }
 
return 0;
}
