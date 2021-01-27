 #include <iostream>
 #include <string>
 using namespace std;
 int main()
 {
     int num=0,sum=0;
     string s;
     cin>>s;
     for(int i=0;i<s.length();i++)
     {
         if(s[i]=='@')
         {
             num++;
         }
     }
 	int d[50],t=0;
     for(int i=0;i<s.length();i++)
     {
         if(s[i]=='@')
         {
             d[t]=i;
             t++;
         }
     }
     for(int i=0;i<num;i++)
     {
        int x=0,y=1,z=0,n;
        if(i==0)
        {
        	for(int b=0;b<d[i];b++)
        	{
            	bool flag=1;
            	if(97<=s[b]&&s[b]<=122)
            	{
                	for(int m=b+1;m<d[i];m++)
               	 	{
                    	if((97<=s[m]&&s[m]<=122)||(s[m]>=48&&s[m]<=57)||s[m]=='_')
                    	{  

                    	}
                    	else
                    	{
                       	 	flag=0;
                        	break;
                    	}   
            		}
            	}
            	else 
            	{
            		flag=0;
				}
				if(flag)
				{
					x++;
				}
      	  	}
		}
		else
		{
			for(int b=d[i-1]+1;b<d[i];b++)
            {
                bool flag=1;
                if(97<=s[b]&&s[b]<=122)
                {
                    for(int m=b+1;m<d[i];m++)
                    {
                        if((97<=s[m]&&s[m]<=122)||(s[m]>=48&&s[m]<=57)||s[m]=='_')
                        {  

                        }
                        else
                        {
                            flag=0;
                            break;
                        }   
            	    }
                }
                else 
                {
            	    flag=0;
			    }
			    if(flag)
			    {
				    x++;
			    }
            }
		}
        if(i==num-1)
        {
            for(int b=d[i]+1;b<s.length()-1;b++)
            {
                if(s[b]=='.')
                {
                    n=b;
                    break;
                }
                else if((97<=s[b]&&s[b]<=122)||(s[b]>=48&&s[b]<=57))
                {

                }
                else 
                {
                    y=0;
                    break;
                }
            }
        }
        else
        {
             
            for(int b=d[i]+1;b<d[i+1];b++)
            {
                if(s[b]=='.')
                {
                    n=b;
                    break;
                }
                else if((97<=s[b]&&s[b]<=122)||(s[b]>=48&&s[b]<=57))
                {

                }
                else 
                {
                    y=0;
                    break;
                }
            }
        }
        if(i==num-1)
        {
            for(int b=n+1;b<s.length();b++)
            {
                if((97<=s[b]&&s[b]<=122))
                {
                    z++;
                }
                else
                {
                    break;
                }
            
            }
        }
        else
        {
            for(int b=n+1;b<d[i+1];b++)
            {
                if((97<=s[b]&&s[b]<=122))
                {
                    z++;
                }
                else
                {
                    break;
                }
            
            }
        }
        sum=sum+x*y*z;
     }
     cout<<sum;
 }
