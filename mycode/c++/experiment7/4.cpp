#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    string s[T];
    string k[T];
    for(int i=0;i<T;i++)
    {
        int num=0;
        k[i]="safe";
        int x=0;
        cin>>s[i];
        for(int t=0;t<s[i].length();t++)
        {
            if(s[i][t]!='.')
            {
                num++;
            }
        }
        if(num==1)
        {
        	continue;
		}
        int y[num],b=0;
        for(int t=0;t<s[i].length();t++)
        {
            if(s[i][t]!='.')
            {
                y[b]=t;
                b++;
            }
        }	
        for(int t=0;t<num;t++)
        {
            if(t==0)
            {
                if(y[t]+(s[i][y[t]]-48)>=y[t+1]-(s[i][y[t+1]]-48))
                {
                    k[i]="unsafe";
                    break;
                }
            }
            else if(t==num-1)
            {
                if(y[t]-(s[i][y[t]]-48)<=y[t-1]+(s[i][y[t-1]]-48))
                {
                    k[i]="unsafe";
                    break;
                }
            }
            else
            {
                if((y[t]+(s[i][y[t]]-48)>=y[t+1]-(s[i][y[t+1]]-48))||(y[t]-(s[i][y[t]]-48)<=y[t-1]+(s[i][y[t-1]]-48)))
                {
                    k[i]="unsafe";
                    break;
                }
            }
        }
    }
    for(int i=0;i<T;i++)
        {
            cout<<k[i]<<endl;
        }
}
