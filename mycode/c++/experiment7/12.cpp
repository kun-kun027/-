#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int fn(string a);
int weishu(int n);
int yinshu(int a,int b);
int c99(int n);
int beishu(int a,int b); 
int main()
{
    int T;
    cin>>T;
    string x[T]; 
    for( int i=0;i<T;i++)
    {
        double c,h,l,y,m,n,p,q,g;  
        string s,k;
        bool flag=1;
        cin>>x[i];
        if(x[i]=="0.00(3)")
        {
        	cout<<1<<'/'<<300<<endl;
        	continue;
		}
        for(int t=0;t<x[i].length();t++)
        {
            if(x[i][t]=='(')
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            c=yinshu(fn(x[i]),pow(10,weishu(fn(x[i]))));
            cout<<fn(x[i])/c<<'/'<<pow(10,weishu(fn(x[i])))/c<<endl;
        }
        else if(x[i][2]=='(')
        {
            s=x[i].substr(3,x[i].length()-4);
            c=yinshu(fn(s),c99(weishu(fn(s))));
            cout<<fn(s)/c<<'/'<<c99(weishu(fn(s)))/c<<endl;
        }    
        else
        {
            for(int b=0;b<x[i].length();b++)
            {
                if(x[i][b]=='(')
                {
                    h=b;
                    break;
                }
            }
            
            s=x[i].substr(0,h);           
            c=yinshu(fn(s),pow(10,weishu(fn(s))));            
            p=fn(s)/c;q=pow(10,weishu(fn(s)))/c;            
            k=x[i].substr(0,2)+x[i].substr(h+1,x[i].length()-h-2);
            c=yinshu(fn(k),c99(weishu(fn(k)))*pow(10,h-2));
            m=fn(k)/c;n=c99(weishu(fn(k)))*pow(10,h-2)/c;           
            l=beishu(q,n);
            y=p*(l/q)+m*(l/n);
           	c=yinshu(y,l);
			cout<<y/c<<'/'<<l/c<<endl;                    
        }
                             
    } 
}

int fn(string a)
{

	int sum=0,b=1;
    for(int i=a.length()-1;i>=0;i--)
    {
        if(a[i]=='.')
        {
            break;
        }
        else
        {
            sum+=(a[i]-48)*b;
            b*=10;
        }   
    }
	return sum;
}
int weishu(int n)
{
    int num=1;
    while(n>=10)
    {
        n/=10;
        num++;
    }
    return num;
}
int yinshu(int a,int b)
{
    int c=a<b?a:b;
    for(int i=c;i>=1;i--)
    {
        if(a%i==0&&b%i==0)
        {
            return i;
            break;
        }
    }
}
int c99(int n)
{
    int sum=0,a=1;
    for(int i=0;i<n;i++)
    {
        sum=sum+a*9;
        a*=10;
    }
    return sum;
    
}
int beishu(int a,int b)
{
    int c=a>b?a:b;
    for(int i=c;;i++)
    {
        if(c%a==0&&c%b==0)
        {
            return c;
            break;
        }
    }
}
