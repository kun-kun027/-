#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		y[i]=1;
		for(int t=0;t<n;t++)
		{
			if(x[i]<x[t])
			{
				bool flag=0;
				for(int b=0;b<t;b++)
				{
					if(x[b]==x[t])
					{
						flag=1;
					}
				}
				if(!flag)
				{
					y[i]++;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<y[i]<<" ";
	}
} 
