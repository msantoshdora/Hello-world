#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
    cin>>n;
    int a[n];
    
    	for(int i=0;i<n;i++)
    	{
    		 cin>>a[i];
    	}
    	sort(a,a+n);
    	int c=0,temp;
        cout<<n<<endl;
    	for(int i=0;i<n;)
        {   
            c=0;
            for(int j=i+1;j<n;j++)
            {
             a[j]=a[j]-a[i];
             if(a[j]!=0)
               c++;
            }
           if(c!=0)
            cout<<c<<endl;
         a[i]=0;
          while(a[i]==0)
            i++;
        }
    return 0;
}

