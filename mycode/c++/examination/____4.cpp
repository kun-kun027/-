#include <iostream>
using namespace std;
int main()
{
	int i,j;
	cin>>i>>j;
	int a[i][j];
	for(int t=0;t<i;t++)
	{
		for(int b=0;b<j;b++)
		cin>>a[t][b];
	}
	for(int t=0;t<i;t++)
	{
		if(t%2==0)
		{
			for(int c=0;c<j;c++)
			{
				if(c!=j-1)
				{
					cout<<a[t][c]<<" ";
				}
				else
				{
					cout<<a[t][c]<<endl;
				}
			}
			
		}
		else
		{
			for(int d=j-1;d>=0;d--)
			{
				if(d!=0)
				{
					cout<<a[t][d]<<" ";
				}
				else
				{
					cout<<a[t][d]<<endl;
				}
			}
		}
	}
}

