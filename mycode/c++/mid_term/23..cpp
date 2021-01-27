#include <iostream>
using namespace std;
int main()
{
	int x[100],y[100],num=0;
	int sum=0;
	for(int i=0;;i++)
	{
		cin>>x[i];
		if(x[i]==0)
		{
			break;
		}
		if(x[i]==1)
		{
			y[i]=1;
			num++;
		}
		else if(x[i]==2)
		{
			if(x[i-1]==1)
			{
				y[i]=2;
			}
			else
			{
				y[i]=2+y[i-1];
			}
			num++;
		}
	}
	for(int i=0;i<num;i++)
	{
		sum+=y[i];
	}
	cout<<sum;
}
