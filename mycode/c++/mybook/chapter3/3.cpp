#include <iostream>
using namespace std;
int fn(long long a,int b);
int main()
{
    long long a,b;
    int Da,Db;
    cin>>a>>Da>>b>>Db;
    cout<<fn(a,Da)+fn(b,Db);
}
int fn(long long a,int b)
{
    int pa=0;
    while(a!=0)
    {
        if(a%10==b)
        {
            pa=pa*10+b;
        }
        a/=10;
    }
    return pa;
}
