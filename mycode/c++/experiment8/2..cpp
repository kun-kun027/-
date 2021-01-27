#include <iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    int x[m][n],num[n];
    for(int i=0;i<m;i++)
    {
        for(int t=0;t<n;t++)
        {
            cin>>x[i][t];
        }
    }
    for(int t=0;t<n;t++)
    {
        num[t]=0;
    }
    for(int i=0;i<m;i++)
    {
        int max=x[i][0];
        for(int t=0;t<n;t++)
        {
            if(x[i][t]>max)
            {
                max=x[i][t];
            }
        }
        for(int t=0;t<n;t++)
        {
            if(x[i][t]==max)
            {
                num[t]++;
            }
        }
    }
    int max=num[0];
    for(int i=0;i<n;i++)
    {
        if(num[i]>max)
        {
            max=num[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(num[i]==max)
        {
            cout<<i+1;
            break;
        }
    }
}
