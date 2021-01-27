#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            a[j+1]=a[j];
        }
        a[0]=a[n];
    }
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
            cout<<a[i]<<" ";
        else
            cout<<a[i];
    }
}