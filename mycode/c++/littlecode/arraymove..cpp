#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    m=m%n;
    for(int &x:a)
    {
        cin>>x;
    }
    for(int i=n-m;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    for(int i=0;i<n-m;i++)
    {
        if(i!=n-m-1)
            cout<<a[i]<<" ";
        else
            cout<<a[i];
    }
}