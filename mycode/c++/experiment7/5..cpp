#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s,t;
	int num=0;
	cin>>s>>t;
	for(int i=0;;i++)
	{
		if(s==t)
		{
			break;
		}
		else
		{
			if(s.length()==t.length())
			{
				num+=2;
				s.erase(0,1);
				t.erase(0,1);
			}
			else if(s.length()>t.length())
			{
				num++;
				s.erase(0,1);
			}
			else if(s.length()<t.length())
			{
				num++;
				t.erase(0,1);
				
			}
		}
	}
	cout<<num;
}

