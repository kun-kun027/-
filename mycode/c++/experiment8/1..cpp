#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct player
{
    string name;
    int x[7];
    int sum=0;
};
bool cmp(player a,player b)
{
    if(a.sum>b.sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    cin>>n;
    player a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name;
        for(int t=0;t<7;t++)
        {
            cin>>a[i].x[t];
        }
        sort(a[i].x,a[i].x+7);
        for(int t=1;t<6;t++)
        {
            a[i].sum+=a[i].x[t];
        }
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].sum<<endl;
    }
}
