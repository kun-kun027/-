#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int x[n],y[m],z[m+n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>y[i];
	}
	for(int i=0;i<m+n;i++)
	{
		if(i<n)
		{
			z[i]=x[i];
		}
		else
		{
			z[i]=y[i-n];
		}
	}
	sort(z,z+(m+n));
	for(int i=m+n-1;i>=0;i--)
	{
		cout<<z[i]<<" ";
	}
	
}
