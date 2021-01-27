#include <iostream>
using namespace std;
int main()
{
	int n,b=0;
	cin>>n;	
	int x[n];
	for(int i=0;i<n;i++)
	{
		x[i]=i+1;
	}
	for(int a=0;a<n-1;a++)
	{
		int num=0; 
		for(;;b++)
		{
			b=b%n;	
			if(x[b]!=0)
			num++;
			if(num==7)
			{
				x[b]=0;
				b=(b+1)%n;
				break;
				
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(x[i]!=0)
		cout<<x[i];
	}
}

