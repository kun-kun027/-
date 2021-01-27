#include <iostream>
using namespace std;
void qsort(int a[],int low,int high);
void swap(int *a,int *b);
void arrange(int a[],int n);
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int &x:a)
    {
        cin>>x;
    }
    arrange(a,n);
    for(int &x:a)
    {
        cout<<x<<" ";;
    }
    return 0;
}
void arrange(int a[],int n)
{
    int *p=a,*q=a+n-1;
    while(p<q)
    {
        if(*p%2==0&&*q%2!=0)
        {
            swap(p,q);
            p++;
            q--;
        }
        else
        {
            if(*p%2!=0)
            {
                p++;
            }
            if(*q%2==0)
            {
                q--;
            }
        }
    }
    int m;
    if(p==q)
    {
        m=*p%2?(p-a):(p-a-1);
    }
    else
    {
        m=q-a;
    }
    qsort(a,0,m);
    qsort(a,m+1,n-1);
}
void qsort(int *p,int low,int high)
{
    if(high<=low)
    return;
    int key=p[low];
    int i=low,j=high+1;
    while(1)
    {
        while(p[++i]<key)
        {
            if(i==high)
            break;
        }
        while(p[--j]>key)
        {
            if(j==low)
            break;
        }
        if(i>=j)
        break;
        swap(&p[i],&p[j]);
    }
    swap(&p[low],&p[j]);
    qsort(p,low,j-1);
    qsort(p,j+1,high);
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}
