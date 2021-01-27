#include <iostream>
using namespace std;
struct Node
{
    int num;
    Node *next;
};
int main()
{
    int n;
    cin>>n;
    Node a[n];
    for(int i=0;i<10;i++)
    {
        a[i].num=i+1;
    }
    for(int i=0;i<n-1;i++)
    {
        a[i].next=&a[i+1];
    }
    a[n-1].next=&a[0];
    int max=0;int j=0;bool flag=1;


}