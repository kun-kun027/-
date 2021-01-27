#include <iostream>//Ì°ÐÄµÄ°¢µÏ 
using namespace std;
int main()
{
	int n,k,m,d,max=0,s=0;
	cin>>n>>k>>m>>d;
	for(int i=1;i<=m;i++)
	{
		if(n<d*k*i+i)
		{
			if(n<(k*i))
			{
				s=1;
			}
			else if(n/(k*i)==0)
			{
				s=n/(k*i);
			}
			else if(n%(k*i)>=i)
			{
				s=n/(k*i)+1;
			}
			else
			{
				s=n/(k*i);
			}
			if(i*s>max)
			{
				max=i*s;
			}
		}
	}
	cout<<max;
}

