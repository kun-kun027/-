#include <iostream>
using namespace std;
int main()
{
	int n,num=0;
	cin>>n;
	int *x=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		bool flag=0;
		for(int t=0;t<n;t++)
		{
			for(int j=0;j<n;j++)
			{
				if(t!=j&&x[i]==x[j]+x[t])
				{
					num++;
					flag=1;
					break;
				}
			}
			if(flag)
			{
				break;
			}
		}
	}
	cout<<num; 
}
