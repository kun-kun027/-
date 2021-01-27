#include <iostream>
using namespace std;
int main()
{
    int T,A=0,B=0;
    cin>>T;
    while(T--)
    {
        int a,a1,b,b1;
        cin>>a>>a1>>b>>b1;
        if(a1!=a+b)
            A++;
        if(b1!=a+b)
            B++;
        if((a1==a+b&&b1!=a+b)||(a1!=a+b&&b1==a+b))
            break;
    }
    cout<<A<<" "<<B;
}