#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int n[T],m[T],num[T];
	for(int i=0;i<T;i++)
	{
		cin>>n[i]>>m[i];
		num[i]=0;
		if(m[i]<13)
		{
			if(n[i]%m[i]==0)
			{
				num[i]=n[i]/m[i];
			}
			else
			{
				num[i]=n[i]/m[i]+1;
			}
		}
		if(m[i]==13)
		{
			if(n[i]%12==0)
			{
				num[i]=n[i]/12;
			}
			else
			{
				num[i]=n[i]/12+1;
			}
		}
		if(m[i]==14)
		{
			if(n[i]%m[i]==13)
			{
				num[i]=n[i]/m[i]+2;
			}
			else if(n[i]%m[i]==0)
			{
				num[i]=n[i]/m[i];
			}
			else
			{
				num[i]=n[i]/m[i]+1;
			}
		}
		if(m[i]>14) 
		{
			if(n[i]%m[i]==0)
			{
				num[i]=n[i]/m[i];
			}
			else
			{
				num[i]=n[i]/m[i]+1;
			}
		}
	}
	for(int i=0;i<T;i++)
	{
		cout<<num[i]<<endl;
	}
	
} 
