#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "shm_com.h"
int main()
{
 int shmid;
 void *shared_memory=(void *)0;
 struct shared_use_st *p;
 shmid=shmget((key_t)1223,sizeof(struct shared_use_st),0666|IPC_CREAT);
 if(shmid==-1)
 {
   fprintf(stderr,"No shared Memory allocation is available\n");
   exit(0);
 }
 shared_memory=shmat(shmid,(void*)0,0);
 if(shared_memory==(void *)-1)
 {
  fprintf(stderr,"shmat failed\n");
  exit(EXIT_FAILURE);
 }
// printf("Memory attached at %X\n",shared_memory);
 p=(struct shared_use_st *)shared_memory; 
 
 return 0;
}
