#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int N[T],min[T],max[T],num[T];
    for(int i=0;i<T;i++)
    {
    	num[i]=0;
        cin>>N[i]>>min[i]>>max[i];
        int w[N[i]],b[N[i]];
        for(int t=0;t<N[i];t++)
        {
            cin>>w[t]>>b[t];
        }
        for(int c=min[i];c<=max[i];c++)
        {
            int sum=c;
            for(int x=0;x<N[i];x++)
            {
                sum=w[x]*sum+b[x];
            }
            if(sum%2==0)
            num[i]++;          
       }              
    } 
    for(int n=0;n<T;n++)
    {
        cout<<num[n]<<" "<<max[n]-min[n]-num[n]+1<<endl;
    }
    return 0;
    
}
