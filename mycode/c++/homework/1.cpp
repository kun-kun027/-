#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[1000];
    int i=0;
    while(cin>>a[i])
    {
        cout<<a[i]<<" ";
        i++;
    }
    int x[i];
    for(int t=0;t<i;t++)
    {
        x[t]=a[t];
    }
    sort(x,x+i);
    cout<<x[0];
    

}