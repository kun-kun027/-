#include <iostream>
using namespace std;
int main()
{
	long long a,b;
	cin>>a>>b;
	if(a>=0&&b>=0)
	{
		cout<<a*b;
	}
	if(a<0&&b<0) 
	{
		cout<<a*b;
	}
	if(a>=0&&b<0)
	{
		cout<<a+b;
	}
	if(a<0&&b>=0)
	{
		cout<<a+b;
	}
}
