#include <iostream>
using namespace std;
int main()
{
	int time=1349;
	int &x=time;//���ã� 
	cout<<x;
	x-=3;
	cout<<time;
	cout<<&time<<endl<<&x; 
}
