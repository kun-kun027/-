#include <iostream>//°Ý·ÃÅóÓÑ 
using namespace std;
int main()
{
	double i;
	int n,m;
	cin>>n>>m;
	double x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(i=0.5;i<=m-0.5;i++)
	{
		bool flag=0;
		for(int t=0;t<n;t++)
		{
			if((x[t]<i)&&(i<y[t]))
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			break;
		}
	}
	if(i==m+0.5)
	{
		cout<<"Yes";
	}
	else
	cout<<"No";
} 
