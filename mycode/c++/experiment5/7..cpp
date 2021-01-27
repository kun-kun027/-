#include <iostream>//ºï×ÓÊÕÍ½ 
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int r[n],x[k],y[k],num[n];
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}
	for(int i=0;i<k;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++)
	{
		num[i]=0;
		for(int t=0;t<n;t++)
		{
			if(r[i]>r[t])
			{
				bool flag=1; 
				for(int b=0;b<k;b++)
				{
					if((i+1)==x[b]&&(t+1)==y[b])
					{
						flag=0;break;
					}
				}
				if(flag)
				{
					num[i]++;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<num[i]<<" "; 
	} 
}
