#include <iostream>
#include <algorithm>
using namespace std;
struct teacher
{
    int key;
    int begin_time;
    int continue_time;
    int finish_time;
    bool s=0;
};
bool rule1(teacher a,teacher b)
{
    if(a.begin_time<b.begin_time)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
bool rule2(teacher a,teacher b)
{
    if(a.finish_time<b.finish_time)
    {
        return 1;
    }
    else if(a.finish_time==b.finish_time)
    {
        if(a.key<b.key)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }   
    else
    {
        return 0;
    }
}
int main()
{
    int N,K;
    cin>>N>>K;
    int a[N];
    for(int i=0;i<N;i++)
    {
        a[i]=i+1;
    }
    teacher x[K];
    for(int i=0;i<K;i++)
    {
        cin>>x[i].key>>x[i].begin_time>>x[i].continue_time;
        x[i].finish_time=x[i].begin_time+x[i].continue_time;
    }
    sort(x,x+K,rule1);
    for(int i=0;i<K;i++)
    {
        int g=x[i].begin_time;
        sort(x,x+K,rule2);
        for(int t=0;t<K;t++)
        {
            if(x[t].finish_time<=g&&!(x[t].s))
            {
                for(int b=0;b<N;b++)
                {
                    if(a[b]==0)
                    {
                         a[b]=x[t].key;
                        break;
                    }
                }
                x[t].s=1;
            }
        }
        sort(x,x+K,rule1);
        for(int t=0;t<N;t++)
        {
            if(a[t]==x[i].key)
            {
                a[t]=0;
                break;
            }
        }
        sort(x,x+K,rule2);
        if(i==K-1)
        {
            for(int t=0;t<K;t++)
            {
                if(!(x[t].s))
                {
                    for(int b=0;b<N;b++)
                    {
                        if(a[b]==0)
                        {
                            a[b]=x[t].key;
                            break;
                        }
                    }
                    x[t].s=1;
                }
            }
        }
        sort(x,x+K,rule1);
    }
    for(int i=0;i<N;i++)
    {
        cout<<a[i]<<" ";
    }

}