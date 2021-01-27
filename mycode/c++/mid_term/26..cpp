#include <iostream>
using namespace std;
int main()
{
	int n,m,num=0;
	cin>>n>>m;
	int x[m];
	for(int i=0;i<m;i++)
	{
		cin>>x[i];
	}
	int y[n];
	for(int i=0;i<n;i++)
	{
		y[i]=i+1;
	}
	for(int i=0;i<m;i++)
	{
		int a;
		for(int t=0;t<n;t++)
		{
			if(y[t]==x[i])
			{
				a=t;
			}
		}
		for(int b=n-1;b>0;b--)
		{
			if(b<=a)
			{
				y[b]=y[b-1];
			}
		}
		y[0]=x[i];
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
