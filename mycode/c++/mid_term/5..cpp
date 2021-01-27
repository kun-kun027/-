#include <iostream>
using namespace std;
int main()
{
	int n,m,num=0;
	cin>>n>>m;
	int x[m],y[n];
	for(int i=0;i<n;i++)
	{
		y[i]=i+1;
	}
	for(int i=0;i<m;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<m;i++)
	{
		for(int t=n-1;t>=0;t--)
		{
			if(t<x[i])
			{
				if(t!=0)
				{
					y[t]=y[t-1];
				}
				else
				{
					y[t]=x[i];
				}
				
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(y[i]==i+1)
		{
			num++;
		}
	}
	cout<<num;
	
	
}

