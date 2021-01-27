#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int N,sum=0;
	cin>>N;
	int *m=new int[N];
	int *w=new int[N];
	for(int i=0;i<N;i++)
	{
		cin>>m[i];
	}
	for(int i=0;i<N;i++)
	{
		cin>>w[i];
	}
	sort(m,m+N);
	sort(w,w+N);
	for(int i=0;i<N;i++)
	{
		sum+=abs(m[i]-w[i]);
	}
	cout<<sum;
}
