#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int *x=new int[T];
	string *y=new string[T];
	string *k=new string[100];
	for(int i=0;i<T;i++)
	{
		int num1=0,num2=0;
		cin>>x[i]>>y[i];
		for(int t=0;t<x[i]-1;t++)
		{
			if(y[i][t]=='S'&&y[i][t+1]=='T')
			{
				num1++;
			}
			if(y[i][t]=='T'&&y[i][t+1]=='S')
			{
				num2++;
			}
		}
		if(num1>num2)
		{
			k[i]="YES";
		}
		else
		{
			k[i]="NO";
		}
		
	}
	for(int i=0;i<T;i++)
	{
		cout<<k[i]<<endl;
	}

	

	
}
