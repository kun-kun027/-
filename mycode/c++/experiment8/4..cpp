#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct warning
{
    int time;
    char team;
    int num;
    char color;
};
struct player
{
    
    int time;
    char team;
    int num;
    
};
bool cmp(player a,player b)
{
    if(a.time<b.time)
    {
        return 1;
    }
    else if(a.time==b.time)
    {
        if(a.team=='h'&&b.team=='a')
        {
            return 1;
        }
        else if(b.team=='h'&&a.team=='a')
        {
            return 0;
        }
        else
        {
            if(a.num>b.num)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            
        }
    }    
    else
    {
       return 0;
    }
    
}
int main()
{
    string h,a;
    cin>>h>>a;
    int n,sum=0;
    cin>>n;
    warning x[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i].time>>x[i].team>>x[i].num>>x[i].color; 
    }
    for(int i=0;i<n;i++)
    {
        if(x[i].color=='r')
        {
            sum++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int t=0;t<i;t++)
        {
            if(x[i].num==x[t].num&&x[i].team==x[t].team&&x[i].color==x[t].color)
            {
                sum++;
                break;
            }
        }
    }
    if(sum==0)
    {
        cout<<"No Red Card";
    }
    else
    {
        player y[sum];
        int b=0;
        for(int i=0;i<n;i++)
        {
            if(x[i].color=='r')
            {
                y[b].time=x[i].time;
                y[b].team=x[i].team;
                y[b].num=x[i].num;
                b++; 
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int t=0;t<i;t++)
            {
                if(x[i].num==x[t].num&&x[i].team==x[t].team)
                {
                    y[b].time=x[i].time;
                    y[b].team=x[i].team;
                    y[b].num=x[i].num;
                    b++;
                    break;  
                }
            }
        }
        sort(y,y+sum,cmp);
        for(int i=0;i<sum;i++)
        {
            if(y[i].team=='h')
            {
                cout<<h<<" ";
            }
            else
            {
                cout<<a<<" ";
            }
            cout<<y[i].num<<" ";
            cout<<y[i].time<<endl;
        }
    } 
}