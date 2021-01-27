#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b,h,m,s;
    cin>>a>>b;
    int d=abs(a-b);
    if(d%100>=50)
        d=d/100+1;
    else
        d=d/100;
    h=d/3600;
    m=d%3600/60;
    s=d%60;
    if(h<10)
    cout<<0<<h<<":";
    else
    cout<<h<<":";
    if(m<10)
    cout<<0<<m<<":";
    else
    cout<<m<<":";
    if(s<10)
    cout<<0<<s<<":";
    else
    cout<<s<<":";
    return 0;
}