#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	bool flag=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='n'||s[i]=='a'||s[i]=='o'||s[i]=='u'||s[i]=='i'||s[i]=='e')
		{
			continue;
		}
		else
		{
			if(s[i+1]!='a'&&s[i+1]!='o'&&s[i+1]!='u'&&s[i+1]!='i'&&s[i+1]!='e')
			{
				flag=0;
				break;
			}
		}
	}
	if(flag)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}
