#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char *p=new char(10);
	p="hello";
	char *x=new char(9);
	x="hello";
	cout<<strcmp(p,x);
}
