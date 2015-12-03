#include<iostream>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
	long long int n,m,temp,size,i,sum;
	cin>>n;
	long long int a[n]={0};
	cin>>m;
	long long start=m+1;
	sum=0;
	i=start;
	temp=a[i];
	while(a[i]!=-1)
	{
	 sum++;
        	a[i]=-1;
	 i=(temp+start)%n;
	 temp=a[i];
        
	}
      if(sum==n)
      {
       cout<<"Yes"<<endl;
      }
      else
      {
       cout<<"No"<<(n-sum)<<endl;;
      }
   
}
return 0;
}
