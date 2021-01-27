#include <iostream>
using namespace std;
int main()
{
    int n,s,a=0,b=0,c=0;
    cin>>n>>s;
    int h[n],m[n];
    for(int i=0;i<n;i++)
    {
        cin>>h[i]>>m[i];
    }
    for(int t=0;t<n-1;t++)
    {
        int time=0;
        time=(h[t+1]-h[t])*60+m[t+1]-m[t];
        if(time>=2*s+2)
        {
            b=(m[t]+s+1)%60;
            a=h[t]+(m[t]+s+1)/60;
            c=1;
            break;
        }
    }
    if(!c)
    {
   		b=(m[n-1]+s+1)%60;
   		a=h[n-1]+(m[n-1]+s+1)/60;
   		if(a>=24)
   		a=a-24;
   }
    
    cout<<a<<" "<<b;
}
