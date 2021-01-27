#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	string *x=new string[T];
	string *y=new string[T];
	for(int i=0;i<T;i++)
	{
		cin>>x[i];
		int left=0,right=0,c;
		for(int t=0;t<x[i].length();t++)
		{
			if(x[i][t]=='^')
			{
				c=t;
				break;
			}
		}
		for(int t=0;t<x[i].length();t++)
		{
			if(t<c&&x[i][t]!='=')
			{
				left+=(c-t)*(x[i][t]-48);
			}
			if(t>c&&x[i][t]!='=')
			{
				right+=(t-c)*(x[i][t]-48);
			}
		}
		if(right==left)
		{
			y[i]="balance";
		}
		else if(right>left)
		{
			y[i]="right";
		}
		else
		{
			y[i]="left";
		}
	}
	for(int i=0;i<T;i++)
	{
		cout<<y[i]<<endl;
	}

	
	
}
