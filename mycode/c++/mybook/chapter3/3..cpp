#include <iostream>
#include <string>
using namespace std;
int fn(string a,char b);
int main()
{
    string a,b;
    char Da,Db;
    cin>>a>>Da>>b>>Db;
    cout<<fn(a,Da)+fn(b,Db);
}
int fn(string a,char b)
{
    int pa=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==b)
        {
            pa=pa*10+b-48;
        }
    }
    return pa;
}
