#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T,s=0;
	cin>>T;
	int num[T];
	for(int i=0;i<T;i++)
	{
		int n,k,time[k+1];
		cin>>n>>k;
		int x[k];
		for(int t=0;t<k;t++)
		{
			cin>>x[t]; 
		}
		for(int b=0;b<k;b++)
		{
			if(b==0)
			{
				time[b]=x[b];
			}
			else 
			{
				if((x[b]-x[b-1])%2==0)
				{
					s=((x[b]-x[b-1]))/2;
				}
				else
				{
					s=(x[b]-x[b-1]-1)/2;
				}
				time[b]=1+s;
			}
		}
		time[k]=n-x[k-1]+1;
		sort(time,time+(k+1));
		num[i]=time[k];
	}
	for(int i=0;i<T;i++)
	{
		cout<<num[i]<<endl;
	}
} 
