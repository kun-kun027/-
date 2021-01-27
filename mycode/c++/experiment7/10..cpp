#include <iostream>
#include <string>
using namespace std;
int main()
{
	string t;
	getline(cin,t);                                                                                                                                                                                                                                                                                           
	for(int i=1;i<=t.length();i++)
	{
		string x=t;
		if(t.length()%i==0)
		{
			for(int b=0;b<i;b++)
			{
				t[b]=x[i-b-1];
			}
		}
	}
	cout<<t;
}



