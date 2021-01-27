#include <iostream>
using namespace std;
int main()
{
    int x[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int n,m;
    cin>>n;
    int a[n],b; 
    bool flag;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int t=0;t<11;t++)
    {
    	int k;
        flag=0;
        b=1;
        if(t==1)
        {
            if(a[0]==28||a[0]==29)
            {   
                for(k=2;k<1+n;k++)
                {
                    if(k>11&&k%11!=0)
                    {
                    	m=k/11;
                    	k=k-m*11-1;
                    	if(x[k]!=a[b])
                    	{
                    		break;
						}
						k=k+m*11+1;
					}
					else if(k>11&&k%11==0)
					{
						m=k/11;
						k=11;
						if(x[k]!=a[b])
                    	{
                    		break;
                    	}
                    	k=m*k;
                    }
                    else if(k==1)
                    {
                        if(a[b]!=28&&a[b]!=29)
                        break;
                    }
                    else 
                    {
                    	if(x[k]!=a[b])
                    	{
                    		break;
                    	}
					}
                    
                	b++;
                }
                if(k==n+1)
                {
                	flag=1;break;
				}
             }
            
        }    
        else if(x[t]==a[0])
        {
            for(k=t+1;k<t+n;k++)
            {
                if(k>11&&k%11!=0)
                    {
                    	m=k/11;
                    	k=k-m*11-1;
                    	if(x[k]!=a[b])
                    	{
                    		break;
						}
						k=k+m*11+1;
					}
					else if(k>11&&k%11==0)
					{
						m=k/11;
						k=11;
						if(x[k]!=a[b])
                    	{                	
                    		break;
                    	}
                    	k=m*k;
                    }
                    else if(k==1)
                    {
                        if(a[b]!=28&&a[b]!=29)           
                        break;
                    }
                    else 
                    {
                    	if(x[k]!=a[b])
                    	{                	
                    		break;
                    	}
                    	
					}
                	b++;
        	}
        	if(k==n+t)
        	{
        		flag=1;break;
			}
    	}
	}
    if(flag)
    cout<<"Yes";
    else
    cout<<"No";
}    
