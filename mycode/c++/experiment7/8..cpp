#include <iostream>//算折射次数
#include <string>
using namespace std;
struct cube
{
    int x;
    int y;
    bool solid=0;
};
int main()
{
   int n,m;
   cin>>n>>m;
   cube x[(m+2)*(n+2)];
   for(int i=0;i<(m+2)*(n+2);i++)
   {
        if((i+1)%(n+2)==0)
        {
            x[i].x=n+1;
        }
        else
        {
            x[i].x=i%(n+2);
        }
        if(i%(n+2)==n+1)
        {
            x[i].y=(i+1)/(n+2)-1;
        }
        else
        {
            x[i].y=(i+1)/(n+2);
        }
        
        if(x[i].x==0||x[i].x==n+1||x[i].y==0||x[i].y==m+1)
        {
            x[i].solid=1;
        }
        else
        {
            x[i].solid=0;
        }
   }
   int k;
   cin>>k;
   int a[k],c[k];
   for(int i=0;i<k;i++)
   {
       cin>>a[i]>>c[i];
       for(int t=0;t<m*n;t++)
       {
           if(x[t].x==a[i]&&x[t].y==c[i])
           {
               x[t].solid=1;
               break;
           }
       }
   }
   int xs,ys,j,u,num=0;
   string direction1,direction2;
   cin>>xs>>ys>>direction1;
   direction2=direction1;
   j=xs,u=ys;
   while(1)
   {
       if(direction2==direction1&&xs==j&&ys==u&&num!=0)
       {
           break;
       }
       if(direction2=="NE")
       {
           int t;
           for(int i=0;i<(m+2)*(n+2);i++)
           {
               if(x[i].x==xs+1&&x[i].y==ys-1)
               {
                   t=i;
                   break;
               }
           }
           if(x[t].solid==0)
           {
               xs=xs+1;
               ys=ys-1;
               direction2="NE";
               num++;
           }
           else 
           {
               int p,q;
               for(int b=0;b<(m+2)*(n+2);b++)
               { 
                    if(x[b].x==xs&&x[b].y==ys-1)
                    {
                        p=b;
                        break;
                    }
               } 
               for(int b=0;b<(m+2)*(n+2);b++)
               { 
                    if(x[b].x==xs+1&&x[b].y==ys)
                    {
                        q=b;
                        break;
                    }
               } 
               if((x[p].solid==0&&x[q].solid==0)||(x[p].solid!=0&&x[q].solid!=0))
               {
                   direction2="SW";
                   num++;
               }
               if(x[p].solid==0&&x[q].solid!=0)
               {
                   xs=xs;
                   ys=ys-1;
                   direction2="NW";
                   num++;
               }
               if(x[p].solid!=0&&x[q].solid==0)
               {
                   xs+=1;
                   ys=ys;
                   direction2="SE";
                   num++;
               }
           }
           continue;
       }
       if(direction2=="NW")
       {
           int t;
           for(int i=0;i<(m+2)*(n+2);i++)
           {
               if(x[i].x==xs-1&&x[i].y==ys-1)
               {
                   t=i;
                   break;
               }
           }
           if(x[t].solid==0)
           {
               xs=xs-1;
               ys=ys-1;
               direction2="NW";
               num++;
           }
           else 
           {
               int p,q;
               for(int b=0;b<(m+2)*(n+2);b++)
               { 
                    if(x[b].x==xs-1&&x[b].y==ys)
                    {
                        p=b;
                        break;
                    }
               } 
               for(int b=0;b<(m+2)*(n+2);b++)
               { 
                    if(x[b].x==xs&&x[b].y==ys-1)
                    {
                        q=b;
                        break;
                    }
               } 
               if((x[p].solid==0&&x[q].solid==0)||(x[p].solid!=0&&x[q].solid!=0))
               {
                   direction2="SE";
                   num++;
               }
               if(x[p].solid==0&&x[q].solid!=0)
               {
                   xs=xs-1;
                   ys=ys;
                   direction2="SW";
                   num++;
               }
               if(x[p].solid!=0&&x[q].solid==0)
               {
                   xs=xs;
                   ys=ys-1;
                   direction2="NE";
                   num++;
               }
           }
           continue;
       }
       if(direction2=="SE")
       {
           int t;
           for(int i=0;i<(m+2)*(n+2);i++)
           {
               if(x[i].x==xs+1&&x[i].y==ys+1)
               {
                   t=i;
                   break;
               }
           }
           if(x[t].solid==0)
           {
               xs=xs+1;
               ys=ys+1;
               direction2="SE";
               num++;
           }
           else 
           {
               int p,q;
               for(int b=0;b<(m+2)*(n+2);b++)
               { 
                    if(x[b].x==xs&&x[b].y==ys+1)
                    {
                        p=b;
                        break;
                    }
               } 
               for(int b=0;b<(m+2)*(n+2);b++)
               { 
                    if(x[b].x==xs+1&&x[b].y==ys)
                    {
                        q=b;
                        break;
                    }
               } 
               if((x[p].solid==0&&x[q].solid==0)||(x[p].solid!=0&&x[q].solid!=0))
               {
                   direction2="NW";
                   num++;
               }
               if(x[p].solid==0&&x[q].solid!=0)
               {
                   xs=xs;
                   ys=ys+1;
                   direction2="SW";
                   num++;
               }
               if(x[p].solid!=0&&x[q].solid==0)
               {
                   xs=xs+1;
                   ys=ys;
                   direction2="NE";
                   num++;
               }
           }
           continue;
       }
       if(direction2=="SW")
       {
           int t;
           for(int i=0;i<(m+2)*(n+2);i++)
           {
               if(x[i].x==xs-1&&x[i].y==ys+1)
               {
                   t=i;
                   break;
               }
           }
           if(x[t].solid==0)
           {
               xs=xs-1;
               ys=ys+1;
               direction2="SW";
               num++;
           }
           else 
           {
               int p,q;
               for(int b=0;b<(m+2)*(n+2);b++)
               { 
                    if(x[b].x==xs-1&&x[b].y==ys)
                    {
                        p=b;
                        break;
                    }
               } 
               for(int b=0;b<(m+2)*(n+2);b++)
               { 
                    if(x[b].x==xs&&x[b].y==ys+1)
                    {
                        q=b;
                        break;
                    }
               } 
               if((x[p].solid==0&&x[q].solid==0)||(x[p].solid!=0&&x[q].solid!=0))
               {
                   direction2="NE";
                    num++;
               }
               if(x[p].solid==0&&x[q].solid!=0)
               {
                   xs=xs-1;
                   ys=ys;
                   direction2="NW";
                   num++;
               }
               if(x[p].solid!=0&&x[q].solid==0)
               {
                   xs=xs;
                   ys=ys+1;
                   direction2="SE";
                   num++; 
               }
           }
           continue;
       }

   }
    cout<<num;
}