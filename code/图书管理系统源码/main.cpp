#include <bits/stdc++.h>
#include "Book.h"
#include "Library.h"
#include "User.h"
#include "Administrator.h"
#include "Record.h"
#include <fstream> //�������ã��û�ģʽ ����Աģʽ
using namespace std;
int main()
{
    Library HNU;///����������� 
    ifstream ifs;
    ifs.open("books(1).txt", ios::in);
    
    /*if (!ifs)
    {
        cout << "�ļ���ʧ��" << endl; //�����ļ��Ƿ��
    }
    else
    {
        cout << "�ļ��򿪳ɹ�" << endl;
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
        getline(ifs, d); //�����鼮����
        HNU.book[i].SetBookname(a);
        HNU.book[i].SetISBN(b);
        HNU.book[i].SetAuthorname(c);
        HNU.book[i].SetDividename(d);
        HNU.book[i].Addnum(); //��̬��Ա�鼮�������鼮��Ӷ��仯
    }
    long long int account = 1; //Ϊʲôaccount����Ϊ202000000000������
    for (int i = 0; i < 9000; i++)
    {
        HNU.user[i].Setaccount(account);
        account++;
    }
    for (int i = 9000; i < 10000; i++)
    {
        HNU.user[i].Setaccount(0);
    }
    	//HNU.display1();//����鼮�Ƿ����
  first: cout << "1.�û�ģʽ��¼"
         << "		"
         << "2.����Աģʽ��¼"
         << "		"
         << "3.ͼ�����Ϣ����" << endl;
    int a1;
    cin >> a1;
    if (a1 == 1) // �����û���¼����
    { 
    abc:
		bool k = 0;
        long long int id;
        string password;
        system("cls");
        cout << "					"
                "�û���¼����"
             << endl;
        cout << "����������˺ţ�" << endl;
        cin >> id;
        cout << "�������������:" << endl;
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
        	cout<<"��¼�ɹ�����ѡ����Ҫ���еĲ���"<<endl; 
		}
        bcd: cout << "1.�����鼮"
             << "		"
             << "2.�鿴������ʷ"<<endl
             << "3.�鿴������ʷ"<<"		"
         << "4.�޸�����"<<endl<<"5.���ص�¼����"<<"		"<<"6.���س�ʼ����"<<endl;
        int a2;
        cin >> a2;
        if (a2 == 1) //����
        {
            system("cls");
            cout << "��ѡ������ģʽ:" << endl;
            cout << "1.��ȷ����:"
                 << "A.����������"
                 << "		"
                 << "B.��ISBN/ISSN����" << endl;
            cout << "2.ģ��������"
                 << "C.������������"
                 << endl;
                 cout<<"D.������һ��"<<endl;
            char a3;
            cin >> a3;
            if (a3 == 'A') //����������
            {
            	system("cls");
                string a4;
                cout << "����������Ҫ�������������:"<<endl; 
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
                    cout << "��ͼ���û���Ȿ��" << endl;
                    cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ"<<endl;
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
                    cout << "������еĲ���:"
                         << "1.����"
                         << "	"
                         << "2.����"<<endl;
                    int a5;
                    cin >> a5;
                    if (a5 == 1)
                    {
                    	system("cls");
                    	cout<<"����ɹ�"<<endl;
						cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
                    	cout<<"����ɹ�"<<endl;
						cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ" <<endl;
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
            if (a3 == 'B') //��ISBN����
            {
            	system("cls");
                string a4;
                cout << "����������Ҫ���������ISBN/ISSN:"<<endl;
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
                    cout << "��ͼ���û���Ȿ��" << endl;
                    cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ"<<endl;
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
                    cout << "������еĲ���:"
                         << "1.����"
                         << "	"
                         << "2.����"<<endl;
                    int a5;
                    cin >> a5;
                    if (a5 == 1)
                    {
                    	system("cls");
                    	cout<<"����ɹ�"<<endl;
						cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ" <<endl;
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
                    	cout<<"����ɹ�"<<endl;
						cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ" <<endl;
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
            if (a3 == 'C') //������������
            {
            	system("cls");
                string a4;
                cout << "����������Ҫ�������������:"<<endl; 
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
                    cout << "��ͼ���û���Ȿ��" << endl;
                    cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ"<<endl;
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
                    cout << "������еĲ���:"
                         << "1.����"
                         << "	"
                         << "2.����" << endl;
                    int a5;
                    cin >> a5;
                    if (a5 == 1)
                    {
                        string ak;
                        cout << "����������Ҫ����������:";
                        cin>>ak;
                        for (int i = 0; i < 10000; i++)
                        {
                            if (HNU.book[i].GetBookname() == ak)
                            {
                            	system("cls");
                            	cout<<"����ɹ�"<<endl;
								cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ" <<endl;
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
                        cout << "����������Ҫ�����������:";
                        cin >> ak;
                        for (int i = 0; i < 10000; i++)
                        {
                            if (HNU.book[i].GetBookname() == ak)
                            {
                            	system("cls");
                            	cout<<"����ɹ�"<<endl;;
								cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û����ܲ˵�"<<"		"<<"2.�˳�ϵͳ" <<endl;
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
        if (a2 == 2) //�鿴������ʷ
        {
        	system("cls");
        	int k;
        	cout<<"1.�鿴������ʷ"<<"		"<<"2.������һ��"<<endl;
        	cin>>k;
        	if(k==1)
        	{
        		system("cls");
        		HNU.user[personi].displayHistory();
        		cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����û��˵�"<<"		"<<"2.�˳�ϵͳ"<<endl;
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
        	cout<<"1.�鿴������ʷ"<<"		"<<"2.������һ��"<<endl;
        	cin>>k;
        	if(k==1)
        	{
        		system("cls");
        		int m;
        		HNU.user[personi].displayHistory1();
        		cout<<"��ѡ����Ҫ���еĲ���:"<<"1.�����û��˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
        if (a2 == 4) //�޸�����
        {
        	system("cls");
        	int k;
        	cout<<"1.�޸�����"<<"		"<<"2.������һ��"<<endl; 
        	cin>>k;
        	if(k==1)
            {
            	system("cls");
            	cout << "���������������:"<<endl; 
            string newpassword;
            cin >> newpassword;
            HNU.user[personi].Changepassword(newpassword);
            cout<<"�޸ĳɹ�,�����µ�¼"<<","<<"������1ȷ��"<<endl; 
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
if (a1 == 2) //�������Ա��¼����
{
    string id;
    string password;
def:    system("cls");
    cout << "					"
            "����Ա��¼����"
         << endl;
    cout << "����������˺ţ�" << endl;
    cin >> id;
    cout << "�������������:" << endl;
    cin >> password;
    bool k = 0;
    if (password == "20030207" && id == "20030207")
    {
    	caidan2: 
        k = 1;
        cout << "��¼�ɹ�";
        system("cls");
        cout << "1.����˺�"
             << "		"
             << "2.ɾ���˺�"
             << "		" << endl;
           cout   << "3.����ͼ��" << "		"
        << "4.ɾ��ͼ��"<<endl;
           cout  << "5.����ͼ��" <<"		" 
         << "6.�ָ�Ĭ������" <<endl<<"7.�޸�ͼ����Ϣ" <<"		"<<"8.���ص�¼����"<<endl; 
         cout<<"9.���س�ʼ����"; 
    }
    if (!k)
    {
        goto def;
    }
    int a2;
    cin >> a2;
    if (a2 == 1) //����˺�
    {
    	system("cls");
        cout << "��������Ҫ�����û����˺�:";
        long long int newid;
        cin >> newid;
        for (int i = 0; i < 10000; i++)
        {
            if (HNU.user[i].Getaccount() == 0)
            {
            	system("cls");
                HNU.user[i].Setaccount(newid);
                cout<<"�û��Ѵ���"<<endl;
                cout<<"�㽫Ҫ���еĲ���:"<<"1.���ع���Ա�˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
    if (a2 == 2) //ɾ���˺�
    {
    	system("cls");
        cout << "����������ɾ���û����˺�:";
        long long int pastid;
        cin >> pastid;
        for (int i = 0; i < 10000; i++)
        {
            if (HNU.user[i].Getaccount() == pastid)
            {
            	system("cls");
                HNU.user[i].Setaccount(0);
                cout<<"���û���ɾ��"<<endl<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.���ع���Ա�˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
    if (a2 == 3) //����ͼ��
    {
    	system("cls");
        cout << "����������Ҫ����������Ϣ:";
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
                cout<<"��ͼ�������"<<endl<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.���ع���Ա�˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
    if (a2 == 4) //ɾ��ͼ��
    {
    	system("cls");
        cout << "����ɾ�����������:";
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
                cout<<"��ͼ����ɾ��"<<endl<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.���ع���Ա�˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
    if (a2 == 5) //����ͼ��
    {
        system("cls");
        cout << "��ѡ������ģʽ:" << endl;
        cout << "1.��ȷ����:"
             << "A.����������"
             << "	"
             << "B.��ISBN/ISSN����" << endl;
        cout << "2.ģ��������"
             << "C.������������"<<endl;
             
        char a3;
        cin >> a3;
        if (a3 == 'A') //����������
        {
        	system("cls");
        	int booki; 
            string a4;
            cout << "����������Ҫ�������������:";
            cin >> a4;
            bool bookflag = 0;
            for (int i = 0; i < 20000; i++)
            {
                if (HNU.book[i].GetBookname() == a4)
                {
                    booki = i;
                    cout << HNU.book[i].GetBookname() << " " << HNU.book[i].GetISBN() << " " << HNU.book[i].GetAuthorname() << " " << HNU.book[i].GetDividename() << endl;
                    bookflag = 1;
                    cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.���ع���Ա�˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
        if (a3 == 'B') //��ISBN����
        {
        	system("cls");
            string a4;
            cout << "����������Ҫ���������ISBN/ISSN:";
            cin >> a4;
            bool bookflag = 0;
            for (int i = 0; i < 10000; i++)
            {
                if (HNU.book[i].GetISBN() == a4)
                {
                    cout << HNU.book[i].GetBookname() << " " << HNU.book[i].GetISBN() << " " << HNU.book[i].GetAuthorname() << " " << HNU.book[i].GetDividename() << endl;
                    bookflag = 1;
                     cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.���ع���Ա�˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
        if (a3 == 'C') //������������
        {
        	system("cls");
            string a4;
            cout << "����������Ҫ�������������:";
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
            cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.���ع���Ա�˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
        cout << "����������ظ�Ĭ��������û����˻�:";
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
        cout << "�ָ�Ĭ������ɹ�"<<endl;
        cout<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.���ع���Ա�˵�"<<"		"<<"2.�˳�ϵͳ"<<endl; 
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
    	cout<<"��ѡ����Ҫ�޸ĵ���Ϣ����:"<<"1.����"<<"	"<<"2.ISBN"<<"	"<<"3.������"<<endl;
		int l;
		cin>>l;
		if(l==1)
		{
			system("cls");
			cout<<"������ԭ����:";
			string a;
			cin>>a;
			cout<<endl;
			string b;
			cout<<"������������:";
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
			 cout<<"�޸ĳɹ�"<<endl<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����޸�������Ϣ"<<"		"<<"2.���ع���Ա�˵�"<<endl;
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
		 	cout<<"������ԭISBN:";
			string a;
			cin>>a;
			cout<<endl;
			string b;
			cout<<"������ISBN:";
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
			 cout<<"�޸ĳɹ�"<<endl<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����޸�������Ϣ"<<"		"<<"2.���ع���Ա�˵�"<<endl;
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
		 	cout<<"��������Ҫ�޸����ߵ��������:";
			string a;
			cin>>a;
			cout<<endl;
			string b;
			cout<<"��������������:";
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
			 cout<<"�޸ĳɹ�"<<endl<<"��ѡ���㽫Ҫ���еĲ���:"<<"1.�����޸�������Ϣ"<<"		"<<"2.���ع���Ա�˵�"<<endl;
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
		cout<<"Ҫ��鿴ͼ����������ݣ���ȷ�����Ƿ�Ϊ����Ա" <<endl;
		cout<<"���������Ա�˺�:";
		cin>>x1;
		cout<<"���������Ա����:" ;
		cin>>x2;
		if(x1=="20030207"&&x2=="20030207")
		{
			caidan3: 
			system("cls");
			cout<<"����֤���ǹ���Ա�����Բ鿴"<<endl;
			cout<<"��ѡ������Ҫ�鿴������:";
			cout<<"1.ͼ������"<<"		"<<"2.�û�����" <<"		"<<"3.�û����ļ�¼����" <<"		"<<"4.�û������¼����"<<endl; 
			cout<<"5.���س�ʼ����"<<endl;
			int x3;
			cin>>x3;
			if(x3==1)
			{
				HNU.display1();
				cout<<"��ѡ�������һ������:"<<"1.����ͼ�������б�"<<"		"<<"2.�˳�ϵͳ"<<endl;
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
						cout<<"�˺�:"<<HNU.user[i].Getaccount()<<" "<<"����:"<<HNU.user[i].Getpassword()<<endl; 
					}
				}
				cout<<"��ѡ�������һ������:"<<"1.����ͼ�������б�"<<"		"<<"2.�˳�ϵͳ"<<endl;
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
						cout<<"�˻�:"<<HNU.user[i].Getaccount();
						cout<<"�û����ļ�¼:"<<endl;
						HNU.user[i].displayHistory();
					}
				}
				cout<<endl;
				cout<<"��ѡ�������һ������:"<<"1.����ͼ�������б�"<<"		"<<"2.�˳�ϵͳ"<<endl;
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
						cout<<"�˺�:";
						cout<<HNU.user[i].Getaccount();
						cout<<"�û������¼:"<<endl; 
						HNU.user[i].displayHistory1();
					}
				}
				cout<<endl;
					cout<<"��ѡ�������һ������:"<<"1.����ͼ�������б�"<<"		"<<"2.�˳�ϵͳ"<<endl;
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
			cout<<"����֤�㲻�ǹ���Ա�����ܽ��д˲���"<<endl; 
			goto first;
		}
	}
tuichu:return 0;
}
