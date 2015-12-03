#include<iostream>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
#include<semaphore.h>
using namespace std;
struct sembuf
{
 int buf[20];
 sem_t lock;
 int sum;
 int in;
 int out;
};

int main()
{
 sembuf *p;
 int rv; 
 int shmid=shmget(0,sizeof(struct sembuf),0777|IPC_CREAT);
 p=(struct sembuf*)shmat(shmid,0,0);
 sem_init(&p->lock,12,1);
  pid_t pid;
 p->sum=0;
 p->in=0;
 p->out=0;
  pid=fork();
 if(pid)
 {
  //Child Producer
  sem_wait(&p->lock);
  cout<<"Unlocked:\n";
   cout<<"in child\n";
  
   for(int i=0;i<20;i++)
     { 
      p->buf[i]=i;
     }
 // p->sum=0;
  
 
   exit(1211);
 }
else
 {
   //consumer parent
   cout<<"Locked:";
   sem_post(&p->lock);
  
    waitpid(pid,&rv,-1);
    cout<<"in parent:\n";
    for(int i=0;i<20;i++)
    {
     p->sum+=p->buf[i];
    }
   cout<<"SUM is:"<<p->sum;
 }
 
 return 0;
}

