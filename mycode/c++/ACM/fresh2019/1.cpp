#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a,b,num=0,s1=0,s2=0,s;
	int x[100],y[100];
	cin>>a>>b;
	for(int i=0;i<100;i++)
	{
		x[i]=0;y[i]=0;
	}
	for(int i=0;i<=99;i++)
	{
		x[i]=a%2;
		a=a/2;
		s1++;
		if(a==0)
		break;
	}
    for(int j=0;j<=99;j++)
    {
    	y[j]=b%2;
    	b=b/2;
		s2++;
		if(b==0)
		break;
	}
	s=s1>s2?s1:s2;
	int p=s-1;
	for(int t=0;t<s;t++)
	{
		if(x[t]!=y[t])
		{
			num+=pow(2,p);
		}
		p--;
	}
	cout<<num;

}