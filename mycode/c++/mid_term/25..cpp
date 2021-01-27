#include <iostream>
using namespace std;
int fn(int n);
int main()
{
	int n;
	cin>>n;
	int x[n][n];
	x[0][0]=1;
	for(int i=0;i<n;i++)
	{
		x[0][i]=fn(i+1);
		for(int t=1;t<n-i;t++)
		{
			x[t][i]=x[t-1][i]+t+i;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int t=0;t<n-i;t++)
		{
			if(t!=n-i-1)
			{
				cout<<x[i][t]<<" ";
			}
			else
			{
				cout<<x[i][t]<<endl;
			}
			
			
			
		}
	}
}
int fn(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i;
	}
	return sum;
}
