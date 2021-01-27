#include <iostream>
using namespace std;
int n,g,r,c;
bool is_green(int ); 
int main()
{
    cin>>n>>g>>r;
    int t[n+1];
    for(int x=0;x<n+1;x++)
    cin>>t[x];
    int q;
    cin>>q;
    int s[q];
    for(int i=0;i<q;i++)
    {
        cin>>s[i];
        for(int k=0;k<n;k++)
        {
            s[i]=s[i]+t[k];
            if(is_green(s[i]))
            s[i]=s[i];
            else
            s[i]=c;
        }
        s[i]=s[i]+t[n];
    }
    for(int m=0;m<q;m++)
    cout<<s[m]<<" ";

}
bool is_green(int t)
{
    bool flag=0;
    int a=0,b=g;
    while(a<=t)
    {
        if(a<=t&&t<b)
        {
            flag=1;break;
        }
        else
        {
            a=a+g+r;b=b+g+r;
        }
    }
    c=a;
    return flag;
}
