#include <iostream>
using namespace std;
int main()
{
	int n,day=1;
	cin>>n;
	int s[n],d[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>d[i];
	}
	for(int i=0;i<n;i++)
	{
		bool flag=0;
		for(;;)
		{
			for(int t=0;;t++)
			{	
				if(day==s[i]+t*d[i])
				{
					flag=1;
					break;
				}
				if(day<s[i]+t*d[i])
				{
					break;
				}
			}
			if(flag)
			{
				day++;
				break;
			}
			day++;
		}
	}
	cout<<day-1;
}
