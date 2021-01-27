#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x[60];
	x[0]=1;
	x[1]=2;
	for(int i=2;i<60;i++)
	{
		x[i]=x[i-1]+x[i-2];
	}
	cout<<x[n-1];
	
}
