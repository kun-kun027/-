#include <iostream>
#include <algorithm>
using namespace std;
struct rich
{
	char name;
	int money;
};
int main()
{
	int N;
	cin>>N;
	rich x[N];
	for(int i=0;i<N;i++)
	{
		cin>>x[i].name>>x[i].money;
	}
	int max=x[0].money;
	rich temp=x[0];
	for(int t=0;t<N;t++)
	{
		if(max<x[t].money)
		{
			temp=x[t];
			max=x[t].money;
		}
	}
	cout<<temp.name<<" "<<temp.money;
	
} 
