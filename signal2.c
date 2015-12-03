#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<wait.h>
#include<string.h>
#include<unistd.h>

void int_handler(int signo)
{
 signal(SIGINT,int_handler);
 fprintf(stderr,"SORRY WILL NOT WORK..TRY OTHER COMMANDS[Ctrl-z]\n"); 
}

int main()
{
 signal(SIGINT,int_handler);
 signal(SIGQUIT,SIG_IGN);
// signal(SIG );

 printf("press [Ctrl-c],[Ctrl-/]\n");
 for(;;)
  pause();
 
 return 0;
}
