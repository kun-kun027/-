#include <iostream>
using namespace std;
bool fn(int);
int main()
{
	int N,num=0;
	cin>>N;
	int x[4]={0,0,0,0};
	for(int i=1;;i++)
	{
		if(!fn(i))
		{
			num++;
		}
		else
		{
			if(i%4==1)
			{
				x[0]++;
			}
			if(i%4==2)
			{
				x[1]++;
			}
			if(i%4==3)
			{
				x[2]++;
			}
			if(i%4==0)
			{
				x[3]++;
			}
		}
			if(num==N)
			{
				break;
			}
	}
	for(int i=0;i<4;i++)
	{
		cout<<x[i]<<" ";
	}

}
bool fn(int n)
{
	if(n%7==0||n%10==7)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
