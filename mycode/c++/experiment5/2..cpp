#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int L[T],v[T],l[T],r[T],num[T];
    for(int i=0;i<T;i++)
    {
        cin>>L[i]>>v[i]>>l[i]>>r[i];
        int x=v[i]; 
        int t=1;
        num[i]=0;
        while(x<=L[i])
        {
            if(x<l[i]||x>r[i])
            num[i]++;
            t++;
            x=t*v[i];
        }
    }
    for(int d=0;d<T;d++)
    cout<<num[d]<<endl;
}
