#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    int x[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    int num=0;
    for(int t=0;t<n-1;t++)
    {
        if(x[t+1]-x[t]==2*d)
        num++;
        if(x[t+1]-x[t]>2*d)
        num+=2;
    }   
    num+=2;
    cout<<num;
       
}
