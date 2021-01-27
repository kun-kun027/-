#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N,s;
	cin>>N>>s;
	int *x=new int[N];
	int *y=new int[N];
	int num[N];
	for(int i=0;i<N;i++)
	{
		cin>>x[i];
		y[i]=abs(x[i]-s);
	}
	for(int i=0;i<N;i++)
	{
		num[i]=0;
		for(int t=0;t<N;t++)
		{
			if(y[i]>y[t])
			{
				num[i]++;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		if(num[i]==0)
		cout<<i+1<<" ";
	}
	for(int i=0;i<N;i++)
	{
		if(num[i]==1)
		cout<<i+1<<" ";
	}
	for(int i=0;i<N;i++)
	{
		if(num[i]==2)
		cout<<i+1;
	}


	
} 
