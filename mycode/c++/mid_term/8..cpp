#include <iostream>
using namespace std;
int main()
{
	int x[3];
	for(int i=0;i<3;i++)
	{
		cin>>x[i];
	}
	int max=x[0];
	for(int i=0;i<3;i++)
	{
		if(x[i]>max)
		{
			max=x[i];
		}
	}
	for(int i=0;i<3;i++)
	{
		if(x[i]==max)
		{
			cout<<x[i]<<" "<<i+1;
			break;
		}
	}
} 
