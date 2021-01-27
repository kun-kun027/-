#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length();)
	{
		if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
		{
			i+=3;
		}
		else
		{
			cout<<s[i];
			i++;
			if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
			{
				cout<<" ";
			}
		}
	}
}
