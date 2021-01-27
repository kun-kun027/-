 #include <iostream> 
 using namespace std;
 int main()
{
 	int n;
 	cin>>n;
 	for(int i=0;i<=n/5;i++)
	{
 		for(int t=0;t<=n/8;t++)
 		{
 			for(int b=0;b<=n/10;b++)
			{
				if(5*i+8*t+10*b==n)
				cout<<"5:"<<i<<" "<<"8:"<<t<<" "<<"10:"<<b<<endl;
			}
 			
		}
	}
 	
 	
 	
	
}

