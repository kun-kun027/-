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
		if(i==0)
		{
			y[i]=(x[0]+x[1]+x[n-1])/3;
		}
		else if(i==n-1)
		{
			y[i]=(x[n-1]+x[n-2]+x[0])/3;
		}
		else
		{
			y[i]=(x[i]+x[i+1]+x[i-1])/3;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<y[i]<<" ";
	}
}
