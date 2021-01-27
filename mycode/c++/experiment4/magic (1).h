# ifndef MAGIC_H_
# define MAGIC_H_
bool isMagic(int a);
# endif
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	isMagic(n);	
}
bool isMagic(int a)
{
	bool flag=1;
	for(int i=1;;i++)
	{
		if(a==0)
		break;
		if(a%10==1)
		a/=10;
		else if(a%100==14)
		a=a/100;
		else if(a%1000)
		a/=1000;
		else
		{
			flag=0;
			break;
		}
	}
	if(flag)
	cout<<"YES";
	else
	cout<<"NO";
}
 
