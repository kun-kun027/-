#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int n[T],h[100];int sum=0,time=0;
    for(int i=0;i<T;i++)
    {
       cin>>n[i]; 
       int l[n[i]],r[n[i]];
       for(int t=0;t<n[i];t++)
       {
           cin>>l[t]>>r[t];
           if(t==0)
           {
           		h[t+sum]=l[t];
           		time=l[t]+1;
		   }
           else if(time<=l[t])
           {
           		h[t+sum]=l[t];
           		time=l[t]+1;
		   }
           else if(time<=r[t])
           {
           		h[t+sum]=time;
           		time=time+1;
		   }
            else
            h[t+sum]=0;
            
       }
       sum=sum+n[i];
    }
    for(int t=0;t<sum;t++)
    {
    	int s=n[0],i;
    	for( i=0;i<T;i++)
    	{
    		if(t==s)
    		{
    			cout<<h[t]<<endl;
    			break;
			}
    		s=s+n[i+1];
    		
		}
    	if(i==T)
		{
			cout<<h[t]<<" ";
		} 
	}
    
}
