#include <iostream>
using namespace std;
int main()
{
	int x[7],y[7],max=0;
	for(int i=0;i<7;i++)
	{
		cin>>x[i]>>y[i];
		if(i==0)
		{
			max=x[i]+y[i];
		}
		else
		{
			if(x[i]+y[i]>max)
			{
				max=x[i]+y[i];
			}
		}
	}
	if(max<=8)
	cout<<0;
	else
	{
		for(int i=0;i<7;i++)
	{
		if(x[i]+y[i]==max)
		{
			cout<<i+1;
			break;
		}
	}
	}

}
