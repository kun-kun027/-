#include <bits/stdc++.h>
#include "Book.h"
#include "Library.h"
#include "User.h"
#include "Administrator.h"
#include "Record.h"
#include <fstream> //界面设置：用户模式 管理员模式
using namespace std;
int main()
{
    Library HNU;///这里出了问题 
    ifstream ifs;
    ifs.open("books(1).txt", ios::in);
    
    /*if (!ifs)
    {
        cout << "文件打开失败" << endl; //检验文件是否打开
    }
    else
    {
        cout << "文件打开成功" << endl;
    }*/
    
   for (int i = 0;; i++)
    {
        string a, b, c, d;
        ifs >> a;
        if (a[0] == '#')
        {
            break;
        }
        ifs >> b >> c;
        getline(ifs, d); //输入书籍资料
        HNU.book[i].SetBookname(a);
        HNU.book[i].SetISBN(b);
        HNU.book[i].SetAuthorname(c);
        HNU.book[i].SetDividename(d);
        HNU.book[i].Addnum(); //静态成员书籍总数随书籍添加而变化
    }
    long long int account = 1; //为什么account设置为202000000000不可以
    for (int i = 0; i < 9000; i++)
    {
        HNU.user[i].Setaccount(account);
        account++;
    }
    for (int i = 9000; i < 10000; i++)
    {
        HNU.user[i].Setaccount(0);
    }
    	//HNU.display1();//输出书籍是否存入
  first: cout << "1.用户模式登录"
         << "		"
         << "2.管理员模式登录"
         << "		"
         << "3.图书馆信息总览" << endl;
    int a1;
    cin >> a1;
    if (a1 == 1) // 进入用户登录界面
    { 
    abc:
		bool k = 0;
        long long int id;
        string password;
        system("cls");
        cout << "					"
                "用户登录界面"
             << endl;
        cout << "请输入你的账号：" << endl;
        cin >> id;
        cout << "请输入你的密码:" << endl;
        cin >> password;
        int personi;
        int booki;
        for (int i = 0; i < 10000; i++)
        {
            if (HNU.user[i].Getaccount() == id && HNU.user[i].Getpassword() == password)
            {
                personi = i;
                k = 1;
                break;
            }
        }
        if (!k)
		{
	    	goto abc;
		}
        system("cls");
       if(k)
        {
        	cout<<"登录成功，请选择你要进行的操作"<<endl; 
		}
        bcd: cout << "1.搜索书籍"
             << "		"
             << "2.查看借阅历史"<<endl
             << "3.查看还书历史"<<"		"
         << "4.修改密码"<<endl<<"5.返回登录界面"<<"		"<<"6.返回初始界面"<<endl;
        int a2;
        cin >> a2;
        if (a2 == 1) //搜索
        {
            system("cls");
            cout << "请选择搜索模式:" << endl;
            cout << "1.精确搜索:"
                 << "A.按书名搜索"
                 << "		"
                 << "B.按ISBN/ISSN搜索" << endl;
            cout << "2.模糊搜索："
                 << "C.按作者名搜索"
                 << endl;
                 cout<<"D.返回上一步"<<endl;
            char a3;
            cin >> a3;
            if (a3 == 'A') //按书名搜索
            {
            	system("cls");
                string a4;
                cout << "请输入你想要搜索的书的书名:"<<endl; 
                cin >> a4;
                bool bookflag = 0;
                for (int i = 0; i < 10000; i++)
                {
                    if (HNU.book[i].GetBookname() == a4)
                    {
                        booki = i;
                        cout << HNU.book[i].GetBookname() << " " << HNU.book[i].GetISBN() << " " << HNU.book[i].GetAuthorname() << " " << HNU.book[i].GetDividename() << endl;
                        bookflag = 1;
                        break;
                    }
                }
                if (!bookflag)
                {
                    cout << "本图书馆没有这本书" << endl;
                    cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统"<<endl;
                    if(k==1)
                        {
                        	system("cls");
                        	goto bcd;
						}
						if(k==2)
						{
							system("cls");
							goto tuichu;
						}
                }
                else
                {
                    cout << "你想进行的操作:"
                         << "1.借书"
                         << "	"
                         << "2.还书"<<endl;
                    int a5;
                    cin >> a5;
                    if (a5 == 1)
                    {
                    	system("cls");
                    	cout<<"借书成功"<<endl;
						cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统"<<endl; 
						int k;
						cin>>k;
                        HNU.book[booki].Borrowbook();
                        HNU.user[personi].SetBorrowHistory(HNU.book[booki].GetBookname(), HNU.book[booki].GetISBN(), HNU.book[booki].GetAuthorname(), HNU.book[booki].GetDividename());
                        if(k==1)
                        {
                        	system("cls");
                        	goto bcd;
						}
						if(k==2)
						{
							system("cls");
							goto tuichu;
						}
                    }
                    if (a5 == 2)
                    {
                    	system("cls");
                    	cout<<"还书成功"<<endl;
						cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统" <<endl;
						int k;
						cin>>k;
                        HNU.book[booki].Returnbook();
                        HNU.user[personi].SetReturnHistory(HNU.book[booki].GetBookname(), HNU.book[booki].GetISBN(), HNU.book[booki].GetAuthorname(), HNU.book[booki].GetDividename());
                        if(k==1)
                        {
                        	system("cls");
                        	goto bcd;
						}
						if(k==2)
						{
							system("cls");
							goto tuichu;
						}
                    }
                }
            }
            if (a3 == 'B') //按ISBN搜索
            {
            	system("cls");
                string a4;
                cout << "请输入你想要搜索的书的ISBN/ISSN:"<<endl;
                cin >> a4;
                int booki;
                bool bookflag = 0;
                for (int i = 0; i < 10000; i++)
                {
                    if (HNU.book[i].GetISBN() == a4)
                    {
                    	booki=i;
                        cout << HNU.book[i].GetBookname() << " " << HNU.book[i].GetISBN() << " " << HNU.book[i].GetAuthorname() << " " << HNU.book[i].GetDividename() << endl;
                        bookflag = 1;
                        break;
                    }
                }
                if (!bookflag)
                {
                    cout << "本图书馆没有这本书" << endl;
                    cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统"<<endl;
                    if(k==1)
                        {
                        	system("cls");
                        	goto bcd;
						}
						if(k==2)
						{
							system("cls");
							goto tuichu;
						}
                }
                else
                {
                    cout << "你想进行的操作:"
                         << "1.借书"
                         << "	"
                         << "2.还书"<<endl;
                    int a5;
                    cin >> a5;
                    if (a5 == 1)
                    {
                    	system("cls");
                    	cout<<"借书成功"<<endl;
						cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统" <<endl;
						int k;
						cin>>k;
                        HNU.book[booki].Borrowbook();
                        HNU.user[personi].SetBorrowHistory(HNU.book[booki].GetBookname(), HNU.book[booki].GetISBN(), HNU.book[booki].GetAuthorname(), HNU.book[booki].GetDividename());
                        if(k==1)
                        {
                        	system("cls");
                        	goto bcd;
						}
						if(k==2)
						{
							system("cls");
							goto tuichu;
						}
                    }
                    if (a5 == 2)
                    {
                    	system("cls");
                    	cout<<"还书成功"<<endl;
						cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统" <<endl;
						int k;
						cin>>k;
                        HNU.book[booki].Returnbook();
                        HNU.user[personi].SetReturnHistory(HNU.book[booki].GetBookname(), HNU.book[booki].GetISBN(), HNU.book[booki].GetAuthorname(), HNU.book[booki].GetDividename());
                    	if(k==1)
                        {
                        	system("cls");
                        	goto bcd;
						}
						if(k==2)
						{
							system("cls");
							goto tuichu;
						}
					}
                }
            }
            if (a3 == 'C') //按作者名搜索
            {
            	system("cls");
                string a4;
                cout << "请输入你想要搜索的书的作者:"<<endl; 
                cin >> a4;
                bool bookflag = 0;
                int booki;
                for (int i = 0; i < 10000; i++)
                {
                    if (HNU.book[i].GetAuthorname() == a4)
                    {
                    	booki=i;
                        cout << HNU.book[i].GetBookname() << " " << HNU.book[i].GetISBN() << " " << HNU.book[i].GetAuthorname() << " " << HNU.book[i].GetDividename() << endl;
                        bookflag = 1;
                    }
                }
                if (!bookflag)
                {
                    cout << "本图书馆没有这本书" << endl;
                    cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统"<<endl;
                    if(k==1)
                        {
                        	system("cls");
                        	goto bcd;
						}
						if(k==2)
						{
							system("cls");
							goto tuichu;
						}
                }
                else
                {
                    cout << "你想进行的操作:"
                         << "1.借书"
                         << "	"
                         << "2.还书" << endl;
                    int a5;
                    cin >> a5;
                    if (a5 == 1)
                    {
                        string ak;
                        cout << "请输入你想要借的书的书名:";
                        cin>>ak;
                        for (int i = 0; i < 10000; i++)
                        {
                            if (HNU.book[i].GetBookname() == ak)
                            {
                            	system("cls");
                            	cout<<"借书成功"<<endl;
								cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统" <<endl;
								int k;
								cin>>k;
                                HNU.book[i].Borrowbook();
                        		HNU.user[personi].SetBorrowHistory(HNU.book[i].GetBookname(), HNU.book[i].GetISBN(), HNU.book[i].GetAuthorname(), HNU.book[i].GetDividename());
                            	if(k==1)
                        		{
                        			system("cls");
                        			goto bcd;
								}
								if(k==2)
								{
									system("cls");
									goto tuichu;
								}
							}
                        }
                    }
                    if (a5 == 2)
                    {
                        string ak;
                        cout << "请输入你想要还的书的书名:";
                        cin >> ak;
                        for (int i = 0; i < 10000; i++)
                        {
                            if (HNU.book[i].GetBookname() == ak)
                            {
                            	system("cls");
                            	cout<<"还书成功"<<endl;;
								cout<<"请选择你将要进行的操作:"<<"1.返回用户功能菜单"<<"		"<<"2.退出系统" <<endl;
								int k;
								cin>>k;
                                HNU.book[i].Returnbook();
                        		HNU.user[personi].SetReturnHistory(HNU.book[i].GetBookname(), HNU.book[i].GetISBN(), HNU.book[i].GetAuthorname(), HNU.book[i].GetDividename());
                            	if(k==1)
                        		{
                        			system("cls");
                        			goto bcd;
								}
								if(k==2)
								{
									system("cls");
									goto tuichu;
								}
							}
                        }
                    }
                }
            }
            if(a3=='D')
			{
				system("cls");
				goto bcd;
			}
        }
        if (a2 == 2) //查看借阅历史
        {
        	system("cls");
        	int k;
        	cout<<"1.查看借阅历史"<<"		"<<"2.返回上一步"<<endl;
        	cin>>k;
        	if(k==1)
        	{
        		system("cls");
        		HNU.user[personi].displayHistory();
        		cout<<"请选择你将要进行的操作:"<<"1.返回用户菜单"<<"		"<<"2.退出系统"<<endl;
				int k;
				cin>>k;
				if(k==1)
				{
					system("cls");
					goto bcd;
				 } 
			}
			if(k==2)
			{
				system("cls");
				goto bcd;
			}
        }
        if(a2==3)
        {
        	system("cls");
        	int k;
        	cout<<"1.查看还书历史"<<"		"<<"2.返回上一步"<<endl;
        	cin>>k;
        	if(k==1)
        	{
        		system("cls");
        		int m;
        		HNU.user[personi].displayHistory1();
        		cout<<"请选择你要进行的操作:"<<"1.返回用户菜单"<<"		"<<"2.退出系统"<<endl; 
        		cin>>m;
        		if(m==1)
        		{
        			system("cls");
        			goto bcd;
				}
				if(m==2)
				{
					system("cls");
					goto tuichu; 
				}
			}
			if(k==2)
			{
				system("cls");
				goto bcd;
			}
		}
        if (a2 == 4) //修改密码
        {
        	system("cls");
        	int k;
        	cout<<"1.修改密码"<<"		"<<"2.返回上一部"<<endl; 
        	cin>>k;
        	if(k==1)
            {
            	system("cls");
            	cout << "请输入你的新密码:"<<endl; 
            string newpassword;
            cin >> newpassword;
            HNU.user[personi].Changepassword(newpassword);
            cout<<"修改成功,将重新登录"<<","<<"请输入1确定"<<endl; 
            int m;
            cin>>m;
            if(m==1)
            {
            	system("cls");
				goto abc;
			}
			}
			if(k==2)
			{
				system("cls");
				goto bcd;
			}
        }
        if(a2==5)
        {
        		system("cls");
				goto abc;
		}
		if(a2==6)
		{
			system("cls");
				goto first;
		}
        
    }
if (a1 == 2) //进入管理员登录界面
{
    string id;
    string password;
def:    system("cls");
    cout << "					"
            "管理员登录界面"
         << endl;
    cout << "请输入你的账号：" << endl;
    cin >> id;
    cout << "请输入你的密码:" << endl;
    cin >> password;
    bool k = 0;
    if (password == "20030207" && id == "20030207")
    {
    	caidan2: 
        k = 1;
        cout << "登录成功";
        system("cls");
        cout << "1.添加账号"
             << "		"
             << "2.删除账号"
             << "		" << endl;
           cout   << "3.增加图书" << "		"
        << "4.删除图书"<<endl;
           cout  << "5.搜索图书" <<"		" 
         << "6.恢复默认密码" <<endl<<"7.修改图书信息" <<"		"<<"8.返回登录界面"<<endl; 
         cout<<"9.返回初始界面"; 
    }
    if (!k)
    {
        goto def;
    }
    int a2;
    cin >> a2;
    if (a2 == 1) //添加账号
    {
    	system("cls");
        cout << "请输入你要创建用户的账号:";
        long long int newid;
        cin >> newid;
        for (int i = 0; i < 10000; i++)
        {
            if (HNU.user[i].Getaccount() == 0)
            {
            	system("cls");
                HNU.user[i].Setaccount(newid);
                cout<<"用户已创建"<<endl;
                cout<<"你将要进行的操作:"<<"1.返回管理员菜单"<<"		"<<"2.退出系统"<<endl; 
                int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan2; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				}
            }
        }
    }
    if (a2 == 2) //删除账号
    {
    	system("cls");
        cout << "请输入你想删除用户的账号:";
        long long int pastid;
        cin >> pastid;
        for (int i = 0; i < 10000; i++)
        {
            if (HNU.user[i].Getaccount() == pastid)
            {
            	system("cls");
                HNU.user[i].Setaccount(0);
                cout<<"该用户已删除"<<endl<<"请选择你将要进行的操作:"<<"1.返回管理员菜单"<<"		"<<"2.退出系统"<<endl; 
                 int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan2; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				}
				 
            }
        }
    }
    if (a2 == 3) //增加图书
    {
    	system("cls");
        cout << "请输入你想要增添的书的信息:";
        string a, b, c, d;
        cin >> a >> b >> c;
        getline(cin, d);
        for (int i = 0; i < 20000; i++)
        {
            if (HNU.book[i].GetBookname() == "")
            {
            	system("cls");
                HNU.book[i].SetBookname(a);
                HNU.book[i].SetISBN(b);
                HNU.book[i].SetAuthorname(c);
                HNU.book[i].SetDividename(d);
                cout<<"该图书已添加"<<endl<<"请选择你将要进行的操作:"<<"1.返回管理员菜单"<<"		"<<"2.退出系统"<<endl; 
                 int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan2; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				}
            }
        }
    }
    if (a2 == 4) //删除图书
    {
    	system("cls");
        cout << "你想删除的书的书名:";
        string PastBookname;
        cin >> PastBookname;
        for (int i = 0; i < 20000; i++)
        {
            if (HNU.book[i].GetBookname() == PastBookname)
            {
            	system("cls");
                HNU.book[i].SetBookname("");
                HNU.book[i].SetISBN("");
                HNU.book[i].SetAuthorname("");
                HNU.book[i].SetDividename("");
                cout<<"该图书已删除"<<endl<<"请选择你将要进行的操作:"<<"1.返回管理员菜单"<<"		"<<"2.退出系统"<<endl; 
                 int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan2; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				}
            }
        }
    }
    if (a2 == 5) //搜索图书
    {
        system("cls");
        cout << "请选择搜索模式:" << endl;
        cout << "1.精确搜索:"
             << "A.按书名搜索"
             << "	"
             << "B.按ISBN/ISSN搜索" << endl;
        cout << "2.模糊搜索："
             << "C.按作者名搜索"<<endl;
             
        char a3;
        cin >> a3;
        if (a3 == 'A') //按书名搜索
        {
        	system("cls");
        	int booki; 
            string a4;
            cout << "请输入你想要搜索的书的书名:";
            cin >> a4;
            bool bookflag = 0;
            for (int i = 0; i < 20000; i++)
            {
                if (HNU.book[i].GetBookname() == a4)
                {
                    booki = i;
                    cout << HNU.book[i].GetBookname() << " " << HNU.book[i].GetISBN() << " " << HNU.book[i].GetAuthorname() << " " << HNU.book[i].GetDividename() << endl;
                    bookflag = 1;
                    cout<<"请选择你将要进行的操作:"<<"1.返回管理员菜单"<<"		"<<"2.退出系统"<<endl; 
                    int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan2; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				}
                }
            }
        }
        if (a3 == 'B') //按ISBN搜索
        {
        	system("cls");
            string a4;
            cout << "请输入你想要搜索的书的ISBN/ISSN:";
            cin >> a4;
            bool bookflag = 0;
            for (int i = 0; i < 10000; i++)
            {
                if (HNU.book[i].GetISBN() == a4)
                {
                    cout << HNU.book[i].GetBookname() << " " << HNU.book[i].GetISBN() << " " << HNU.book[i].GetAuthorname() << " " << HNU.book[i].GetDividename() << endl;
                    bookflag = 1;
                     cout<<"请选择你将要进行的操作:"<<"1.返回管理员菜单"<<"		"<<"2.退出系统"<<endl; 
                    int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan2; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				}
                }
            }
        }
        if (a3 == 'C') //按作者名搜索
        {
        	system("cls");
            string a4;
            cout << "请输入你想要搜索的书的作者:";
            cin >> a4;
            bool bookflag = 0;
            for (int i = 0; i < 20000; i++)
            {
                if (HNU.book[i].GetAuthorname() == a4)
                {
                    cout << HNU.book[i].GetBookname() << " " << HNU.book[i].GetISBN() << " " << HNU.book[i].GetAuthorname() << " " << HNU.book[i].GetDividename() << endl;
                    bookflag = 1;
                }
            }
            cout<<"请选择你将要进行的操作:"<<"1.返回管理员菜单"<<"		"<<"2.退出系统"<<endl; 
                    int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan2; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				}
        }
       
    }
    if (a2 == 6)
    {
        cout << "请输入你想回复默认密码的用户的账户:";
        long long int id1;
        cin >> id1;
        for (int i = 0; i < 5000; i++)
        {
            if (HNU.user[i].Getaccount() == id1)
            {
                HNU.user[i].Changepassword("123456");
                break;
            }
        }
        system("cls");
        cout << "恢复默认密码成功"<<endl;
        cout<<"请选择你将要进行的操作:"<<"1.返回管理员菜单"<<"		"<<"2.退出系统"<<endl; 
                    int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan2; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				}
        
    }
    if(a2==7)
    {
    xiugai:
    	system("cls");
    	cout<<"请选择你要修改的信息类型:"<<"1.书名"<<"	"<<"2.ISBN"<<"	"<<"3.作者名"<<endl;
		int l;
		cin>>l;
		if(l==1)
		{
			system("cls");
			cout<<"请输入原书名:";
			string a;
			cin>>a;
			cout<<endl;
			string b;
			cout<<"请输入新书名:";
			cin>>b;
			cout<<endl;
			for(int i=0;i<20000;i++)
			{
				if(HNU.book[i].GetBookname()==a)
				{
					HNU.book[i].SetBookname(b);
					break;
					
				}
			 } 
			 system("cls");
			 cout<<"修改成功"<<endl<<"请选择你将要进行的操作:"<<"1.继续修改其他信息"<<"		"<<"2.返回管理员菜单"<<endl;
			 int m;
			 cin>>m;
			 if(m==1)
			 {
			 	system("cls");
			 	goto xiugai;
			 }
			 if(m==2)
			 {
			 	system("cls");
			 	goto caidan2;
			 }
		 } 
		 if(l==2)
		 {
		 	system("cls");
		 	cout<<"请输入原ISBN:";
			string a;
			cin>>a;
			cout<<endl;
			string b;
			cout<<"请输入ISBN:";
			cin>>b;
			cout<<endl;
			for(int i=0;i<20000;i++)
			{
				if(HNU.book[i].GetISBN()==a)
				{
					HNU.book[i].SetISBN(b);
					break;
					
				}
			 } 
			 system("cls");
			 cout<<"修改成功"<<endl<<"请选择你将要进行的操作:"<<"1.继续修改其他信息"<<"		"<<"2.返回管理员菜单"<<endl;
			 int m;
			 cin>>m;
			 if(m==1)
			 {
			 	system("cls");
			 	goto xiugai;
			 }
			 if(m==2)
			 {
			 	system("cls");
			 	goto caidan2;
			 }
		 }
		 if(l==3)
		 {
		 	system("cls");
		 	cout<<"请输入你要修改作者的书的书名:";
			string a;
			cin>>a;
			cout<<endl;
			string b;
			cout<<"请输入新作者名:";
			cin>>b;
			cout<<endl;
			for(int i=0;i<20000;i++)
			{
				if(HNU.book[i].GetBookname()==a)
				{
					HNU.book[i].SetAuthorname(b);
					break;
					
				}
			 } 
			 system("cls");
			 cout<<"修改成功"<<endl<<"请选择你将要进行的操作:"<<"1.继续修改其他信息"<<"		"<<"2.返回管理员菜单"<<endl;
			 int m;
			 cin>>m;
			 if(m==1)
			 {
			 	system("cls");
			 	goto xiugai;
			 }
			 if(m==2)
			 {
			 	system("cls");
			 	goto caidan2;
			 }
		 }
	}
    if(a2==8)
    {
    	goto def;
	}
	if(a2==9)
	{
		system("cls");
		goto first;
	 } 

}
	if(a1==3)
	{
		system("cls");
		string x1,x2; 
		cout<<"要想查看图书馆总体数据，得确认你是否为管理员" <<endl;
		cout<<"请输入管理员账号:";
		cin>>x1;
		cout<<"请输入管理员密码:" ;
		cin>>x2;
		if(x1=="20030207"&&x2=="20030207")
		{
			caidan3: 
			system("cls");
			cout<<"经验证你是管理员，可以查看"<<endl;
			cout<<"请选择你想要查看的内容:";
			cout<<"1.图书总览"<<"		"<<"2.用户总览" <<"		"<<"3.用户借阅记录总览" <<"		"<<"4.用户还书记录总览"<<endl; 
			cout<<"5.返回初始界面"<<endl;
			int x3;
			cin>>x3;
			if(x3==1)
			{
				HNU.display1();
				cout<<"请选择你的下一步操作:"<<"1.返回图书总览列表"<<"		"<<"2.退出系统"<<endl;
				int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan3; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				} 
			}
			if(x3==2)
			{
				for(int i=0;i<10000;i++)
				{
					if(HNU.user[i].Getaccount()!=0)
					{
						cout<<"账号:"<<HNU.user[i].Getaccount()<<" "<<"密码:"<<HNU.user[i].Getpassword()<<endl; 
					}
				}
				cout<<"请选择你的下一步操作:"<<"1.返回图书总览列表"<<"		"<<"2.退出系统"<<endl;
				int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan3; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				} 
			}
			if(x3==3)
			{
					system("cls");
				for(int i=0;i<10000;i++)
				{
					if(HNU.user[i].Getaccount()!=0&&HNU.user[i].GetBorrownum()!=0)
					{
						cout<<"账户:"<<HNU.user[i].Getaccount();
						cout<<"用户借阅记录:"<<endl;
						HNU.user[i].displayHistory();
					}
				}
				cout<<endl;
				cout<<"请选择你的下一步操作:"<<"1.返回图书总览列表"<<"		"<<"2.退出系统"<<endl;
					int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan3; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				} 
			}
			if(x3==4)
			{
				system("cls");
				for(int i=0;i<10000;i++)
				{
					if(HNU.user[i].Getaccount()!=0&&HNU.user[i].GetReturnnum()!=0)
					{
						cout<<"账号:";
						cout<<HNU.user[i].Getaccount();
						cout<<"用户还书记录:"<<endl; 
						HNU.user[i].displayHistory1();
					}
				}
				cout<<endl;
					cout<<"请选择你的下一步操作:"<<"1.返回图书总览列表"<<"		"<<"2.退出系统"<<endl;
					int m;
                cin>>m;
                if(m==1)
                {
                	system("cls");
                	goto caidan3; 
				}
				if(m==2)
				{
					system("cls");
					goto tuichu;
				} 
			}
			if(x3==5)
			{
				system("cls");
				goto first;
			 } 
		}
		else
		{
			cout<<"经验证你不是管理员，不能进行此操作"<<endl; 
			goto first;
		}
	}
tuichu:return 0;
}
