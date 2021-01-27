#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	int sum=x[0];
	 for(int i=1;i<=n;i++)
	 {
	 	for(int t=1;t<=n+1-i;t++)
	 	{
	 		int a=0;
	 		for(int b=t-1;b<t+i-1;b++)
	 		{
	 			a+=x[b];
			}
			if(a>sum)
			{
				sum=a;
			}
		}
	}
	cout<<sum;
	 
} 
