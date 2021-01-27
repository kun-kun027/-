#include <iostream>
#include <string>
using namespace std;
bool fn(char);
int main()
{
	int N;
	double time=0;
	cin>>N;
	string *y=new string[N];
	for(int i=0;i<N;i++)
	{
		cin>>y[i];
	}
	for(int i=0;i<N;i++)
	{
		bool chonghe=0;
		for(int n=0;n<i;n++)
		{
			if(y[i]==y[n])
			{
				chonghe=1;
			}
		}
		for(int t=0;t<y[i].length();t++)
		{
			if(t==0)
			{
				if(chonghe)
				{
					time+=0.1;
				}
				else
				{
					time+=0.2;
				}
					
				
			}
			else if(fn(y[i][t])!=fn(y[i][t-1])) 
			{
				if(chonghe)
				{
					time+=0.1;
				}
				else
				{
					time+=0.2;
				}
			}
			else if(fn(y[i][t])==fn(y[i][t-1])) 
			{
				if(chonghe)
				{
					time+=0.2;
				}
				else
				{
					time+=0.4;
				}
			}
		}
	}
	cout<<time*10;
} 
bool fn(char n)
{
	if(n=='q'||n=='Q'||n=='w'||n=='W'||n=='e'||n=='E'||n=='r'||n=='R'||n=='t'||n=='T'||n=='a'||n=='A'||n=='s'||n=='S'||n=='d'||n=='D'||n=='f'||n=='F'||n=='g'||n=='G'||n=='z'||n=='Z'||n=='x'||n=='X'||n=='c'||n=='C'||n=='v'||n=='V'||n=='b'||n=='B')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
