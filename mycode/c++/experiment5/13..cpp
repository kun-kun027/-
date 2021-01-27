#include <iostream>
using namespace std;
int main()
{
    int n,L,a,num=0;
    cin>>n>>L>>a;
    int t[n],l[n];
    for(int i=0;i<n;i++)
    {
        cin>>t[i]>>l[i];
    }
    for(int b=0;b<n;b++)
    {
        if(b==0)
        {
            if(t[b]>=a)
            num=num+t[b]/a;
        }
        else 
        {
            if(t[b]-t[b-1]-l[b-1]>=a)
            num=num+(t[b]-t[b-1]-l[b-1])/a;
        }
        
    }
    num=num+(L-t[n-1]-l[n-1])/a;
    cout<<num;

}
