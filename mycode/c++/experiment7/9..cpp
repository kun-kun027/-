#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int n[T],m[T];
	string k[T];
	for(int i=0;i<T;i++)
	{
		int num1=0,num2=0,num=0;
		int p=0,q=0,y,z;
		k[i]="YES";
		cin>>n[i]>>m[i];
		string x[n[i]];
		for(int t=0;t<n[i];t++)
		{
			cin>>x[t];
		}
		for(int t=0;t<n[i];t++)
		{
			for(int b=0;b<m[i];b++)
			{
				if(x[t][b]=='*')
				{
					num++;
					
				}
			}
		}
		for(int t=0;t<n[i];t++)
		{
			for(int b=0;b<m[i];b++)
			{
				if(x[t][b]=='*')
				{
					num1++;
					break;
				}
			}
		}
		for(int t=0;t<m[i];t++)
		{
			for(int b=0;b<n[i];b++)
			{
				if(x[b][t]=='*')
				{
					num2++;
					break;
				}
			}
		}
		if(num1<=1||num2<=1||num==2)
		{
			continue;
		}
		if(num==3&&num1==3&&num2==3)
		{
			k[i]="NO";
			break;
		}
		for(int t=0;t<n[i];t++)
		{
			p=0;
			for(int b=0;b<m[i];b++)
			{
				if(x[t][b]=='*')
				{
					p++;
				}
			}
			if(p>=2)
			{
				y=t;
				break;
			}
		}
		for(int t=0;t<m[i];t++)
		{
			q=0;
			for(int b=0;b<n[i];b++)
			{
				if(x[b][t]=='*')
				{
					q++;
				}
			}
			if(q>=2)
			{
				z=t;
				break;
			}
		}
		for(int t=0;t<n[i];t++)
		{
			for(int b=0;b<m[i];b++)
			{
				if(x[t][b]=='*')
				{
					if(t!=y&&b!=z)
					{
						k[i]="NO";
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<T;i++)
	{
		cout<<k[i]<<endl;
	}
}
