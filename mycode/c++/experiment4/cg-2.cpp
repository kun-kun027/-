#include <iostream>
using namespace std;
int getCandy(int, int);
int main()
{
    int k, r;
    cin>>k>>r;
    int result=getCandy(k,r);
    cout<<result<<endl;
    return 0;
}
int getCandy(int k,int r)
{
    bool flag=0;int a;
    for(int t=0;;t++)
    {
        for(int i=0;;i++)
        {
        	if(t*k<i*10+r)
               break;
            if(t*k==i*10+r)
            {
                flag=1;a=t;break;
            }
        }
              if(flag)
               break;
    }
        return a;
}

