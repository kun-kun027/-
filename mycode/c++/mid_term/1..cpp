#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T,a; 
	cin>>T;
	int *x=new int[T];
	string *y=new string[T];
	for(int i=0;i<T;i++)
	{
		cin>>x[i];
		int sum=0;
		a=x[i];
		for(int t=0;t<4;t++)
		{
			sum=sum+x[i]%10;
			x[i]/=10;
		}
		if(sum%4==0&&a																																														%3==0)
		{
			y[i]="congratulation!";
		}
		else
		{
			y[i]="sorry!";
		}
	}
	for(int i=0;i<T;i++)
	{
		cout<<y[i]<<endl;
	}


}
