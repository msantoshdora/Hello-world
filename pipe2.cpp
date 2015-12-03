//Find the element is present or not in an array of elements
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<wait.h>
#define BS 30
 
using  namespace std;
int main()
{
 int fd[2];
 pid_t p;
 int ar[BS],n,k,rv;
 cout<<"Enter the size of the array\n";
 cin>>n;
cout<<"Enter the "<<n<<" elements\n";
 for(int i=0;i<n;i++)
  cin>>ar[i];
 cout<<"Enter the key\n";
 cin>>k;
 char ch[BS];
 int index=-1;
 pipe(fd);
 p=fork();
 if(!p)
 {
    /* Child Process 1*/
    for(int i=0;i<n/2;i++)
    {
       if(ar[i]==k)
         index=i;
    }
   sprintf(ch,"%d",index);
   write(fd[1],ch,BS);
   close(fd[1]);
   exit(2);
 }
 else
 { 
   pid_t p2;
  p2=fork();
  if(!p2)
   {
   /* Child Process 2*/
   
   for(int i=n/2;i<n;i++)
   {
     if(ar[i]==k)
        index=i;
   }
   sprintf(ch,"%d",index);
   // open(fd[1]);
   write(fd[1],ch,BS);
   close(fd[1]);
   exit(3);
  }
  else
  {
    waitpid(p,&rv,-1);
    waitpid(p,&rv,-1);
    read(fd[0],ch,BS);
    sscanf(ch,"%d",&n);
    if(n!=-1)
    {
     cout<<"Element is present in the first half\n";
     cout<<"-> "<<n<<endl;
    }
    else
    {
     cout<<"Element is not present in the first half\n";
    }
   read(fd[0],ch,BS);
    sscanf(ch,"%d",&n);
    if(n!=-1)
    {
      cout<<"Element is present in the second half\n";
      cout<<"-> "<<n<<endl; 
    }
    else
    {
    }
  }
 }
 return 0;
}
