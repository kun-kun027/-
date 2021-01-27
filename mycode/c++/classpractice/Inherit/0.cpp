#include<iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
int main()
{
    srand((int)time(0));
    char a[10];
    for(int i=0;i<10;i++)
    {
        a[i]=rand()%25+97;
    }
    sort(a,a+10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i];
    }

}