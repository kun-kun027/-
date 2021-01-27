#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2==0&&n%3==0&&n%5==0)
	{
		cout<<"YES";
	}
	else if(n%2!=0&&n%3!=0&&n%5!=0)
	{
		cout<<"NO";
	}
	else
	{
		if(n%2==0)
		{
			cout<<2<<" ";
		}
		if(n%3==0)
		{
			cout<<3<<" ";
		}
		if(n%5==0)
		{
			cout<<5<<" ";
		}
	}
	
}
