#include <iostream>
using namespace std;
int main()
{
    int n,num=1;
    cin>>n;
    int x[n],t[100],b=0;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        if(x[i]==1&&i!=0)
        {
            num++;
            t[b]=x[i-1];
            b++;
        }
        if(i==n-1) 
        {
        	t[b]=x[n-1];
            b++;
        }
	}
    cout<<num<<endl;
    for(b=0;b<num;b++)
    {
		cout<<t[b]<<" ";
	}
}		
