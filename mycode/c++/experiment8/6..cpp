#include <iostream>
#include <algorithm>
using namespace std;
struct frog
{
    int i;
    int x;
    int length;
    int num=0;
};
struct mosquito
{
    int x;
    int weight;
};
bool cmp(frog a,frog b)
{
    if(a.x<b.x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool caps(frog a,frog b)
{
    if(a.i<b.i)
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
    int n,m,sum=0,sum2=0,h2=0,sum3=0,h3=0,h4=0,sum4=0;
    cin>>n>>m;
    frog a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].length;
    }
    for(int i=0;i<n;i++)
    {
        a[i].i=i+1;
    }
    mosquito b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i].x>>b[i].weight;
    }
    sort(a,a+n,cmp);
    int y[100],h=0,k[100],l[100],p[100];
    for(int i=0;i<m;i++)
    {
    	bool flag=0;
        for(int t=0;t<n;t++)
        {
            if(b[i].x>=a[t].x&&b[i].x<=a[t].x+a[t].length)
            {
                a[t].num++;
                a[t].length+=b[i].weight;
                flag=1;
                break;
            } 
        }
        if(!flag)
            {
            	sum++;
            	y[h]=i;
            	h++;
			}
    }
    for(int i=0;i<sum;i++)
    {
    	bool flag=0;
        for(int t=0;t<n;t++)
        {
            if(b[y[i]].x>=a[t].x&&b[y[i]].x<=a[t].x+a[t].length)
            {
                a[t].num++;
                a[t].length+=b[y[i]].weight;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
        	sum2++;
        	k[h2]=y[i];
        	h2++;
		}
    }
    for(int i=0;i<sum2;i++)
    {
    	bool flag=0;
        for(int t=0;t<n;t++)
        {
            if(b[k[i]].x>=a[t].x&&b[k[i]].x<=a[t].x+a[t].length)
            {
                a[t].num++;
                a[t].length+=b[k[i]].weight;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
        	sum3++;
        	l[h3]=k[i];
        	h3++;
		}
	}	
	for(int i=0;i<sum3;i++)
    {
    	bool flag=0;
        for(int t=0;t<n;t++)
        {
            if(b[l[i]].x>=a[t].x&&b[l[i]].x<=a[t].x+a[t].length)
            {
                a[t].num++;
                a[t].length+=b[l[i]].weight;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
        	sum4++;
        	p[h4]=l[i];
        	h4++;
		}
	}	
	for(int i=0;i<sum4;i++)
    {
        for(int t=0;t<n;t++)
        {
            if(b[p[i]].x>=a[t].x&&b[p[i]].x<=a[t].x+a[t].length)
            {
                a[t].num++;
                a[t].length+=b[p[i]].weight;
                break;
            }
        }
	}	
    sort(a,a+n,caps);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].num<<" "<<a[i].length<<endl;
    }

}
