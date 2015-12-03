#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<wait.h>
#define BS 10
using namespace std;


struct sembuf
{
 int ar[BS];
 sem_t lock;
 sem_t full;
 sem_t empty;
 int in;
 int out;
 int sum;
};

int main()
{
 int pn,cn,rv;
 struct sembuf *p;
 int shmid=shmget(0,sizeof(struct sembuf),0777|IPC_CREAT);
 p=(struct sembuf*)shmat(shmid,0,0);
 sem_init(&p->lock,1,1);    //Lock = 1
 sem_init(&p->full,1,0);
 sem_init(&p->empty,1,BS);
/* Initialising the variables in the shared memory*/
 p->sum=0;
 p->in=0;
 p->out=0;

 cout<<"Enter the number of producers\n";
 cin>>pn;
 cout<<"Enter the number of consumers\n";
 cin>>cn;

  pid_t pid1,pid2;

 /* PRODUCER CODE:*/
 for(int i=0;i<pn;i++)
  {
    if(pid1=fork()==0)
    { 
        //cout<<"Here\n";
      /* Data to be inserted here and Check array is full or not */
       
        for(int j=0;j<BS;j++)
        {
          // cout<<"Here\n";
          //while((a->in+1)%BS==a->out);
         // if((p->in+1)%BS!=p->out)
         // {
          //  cout<<"THIRD\n";
          sem_wait(&p->empty);
          sem_wait(&p->lock);
           // cout<<"FOURTH\n";
          if((p->in+1)%BS!=p->out)
         {
         
             p->ar[p->in]=j;
            p->in=(p->in+1)%BS;
          
        }
                                  //Check this code      
        sem_post(&p->lock); 
        sem_post(&p->full);    
                  //Unlocking the code
      }
 
     exit(0);
    }
  // else
 
  }



  /* CONSUMER CODE*/
  for(int k=0;k<cn;k++)
  { 
   // cout<<"Here111\n"; 
   if(fork()==0)
    {   
    // cout<<"\nPeople\n"; 
     while(p->in!=p->out)
     {
       
     //  cout<<"first\n";
     // while(a->in==a->out);
     sem_wait(&p->full);
      sem_wait(&p->lock);
       cout<<"Second\n";
      if(p->in!=p->out)
      {
       cout<<"third\n";
       p->sum+=p->ar[p->out];  
       p->out=(p->out+1)%BS;
      // cout<<"gggg:"<<p->sum;
      }
       //cout<<p->sum;
      sem_post(&p->lock);
      sem_post(&p->empty);
      //cout<<p->sum<<endl;
     if(p->sum==pn*45)
      break;
      }
    // sem_post(&a->lock); 
     exit(0);
     }
   //exit(12);
  
}
  
while( wait(&rv)>0);
  cout<<"SUM is:\n";
  cout<<p->sum;
 return 0;
}
