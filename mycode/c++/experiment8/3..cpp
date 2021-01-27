#include <iostream>
using namespace std;
struct player
{
    int k;
    int i;
    int e;
};
int main()
{
    int N,num=0;
    cin>>N;
    player x[N];
    for(int i=0;i<N;i++)
    {
        cin>>x[i].k;
    }
    for(int i=0;i<N;i++)
    {
        cin>>x[i].i;
    }
    for(int i=0;i<N;i++)
    {
        cin>>x[i].e;
    }
    for(int i=0;i<N;i++)
    {
        for(int t=0;t<N;t++)
        {
            if(x[t].k>x[i].k&&x[t].i>x[i].i&&x[t].e>x[i].e)
            {
                num++;
                break;
            }
        }
    }
    cout<<num;
}