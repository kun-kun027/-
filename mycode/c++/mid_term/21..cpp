#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int x[10];
	for(int i=0;i<10;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<10;i++)
	{
		if(x[i]!=0&&i!=0)
		{
			x[i]--;
			cout<<i;
			break;
		}
	}
	for(int i=0;i<10;i++)
	{
		for(int t=0;t<x[i];t++)
		{
			cout<<i;
		}
	}
}
	
