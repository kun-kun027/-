#ifndef LIBRARY_H
#define LIBRARY_H
#include <bits/stdc++.h>
#include "User.h"
#include "Library.h"
#include "Book.h"
#include "Administrator.h"
using namespace std;
class Library:public  User,public Book,public Administrator//��ʵ����û�úã�Ӧ�������� 
{
public:
	User*user=new User[10000];//��̬����ռ� 
	Book*book=new Book[20000];
	/*User user[10000];//ͼ��ݽ����û� �鼮 
	Book book[20000];*/
	Administrator administrator;
public:
	void display1()
	{
		for(int i=0;i<book[0].Getnum();i++)//����鼮��Ϣ�������鼮�Ƿ���ȷ���� 
		{
			cout<<book[i].GetBookname()<<" "<<book[i].GetISBN()<<" "<<book[i].GetAuthorname()<<" "<<book[i].GetDividename()<<endl;
		}
	}
};
#endif

