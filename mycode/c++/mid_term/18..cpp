#include <iostream>
using namespace std;
bool fn(int n);
int main()
{
	int l,r,num=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		if(fn(i))
		{
			num++;
		}
	}
	cout<<num;
}
bool fn(int n)
{
	int a=n%10;
	if(n<10)
	{
		return 1;
	}
	while(n>=10)
	{
		n=n/10;
	}
	if(a==n)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
