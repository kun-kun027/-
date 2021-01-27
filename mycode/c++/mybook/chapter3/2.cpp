#include <iostream>
using namespace std;
int main()
{
    int T,num=1;
    cin>>T;
    while(T--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        if(a+b>c)
        cout<<"Case#"<<num<<":true";
        else
        cout<<"Case#"<<num<<":false";
        num++;
    }
}
