#ifndef LIBRARY_H
#define LIBRARY_H
#include <bits/stdc++.h>
#include "User.h"
#include "Library.h"
#include "Book.h"
#include "Administrator.h"
using namespace std;
class Library:public  User,public Book,public Administrator//其实这里没用好，应该用友类 
{
public:
	User*user=new User[10000];//动态分配空间 
	Book*book=new Book[20000];
	/*User user[10000];//图书馆建立用户 书籍 
	Book book[20000];*/
	Administrator administrator;
public:
	void display1()
	{
		for(int i=0;i<book[0].Getnum();i++)//输出书籍信息来检验书籍是否正确输入 
		{
			cout<<book[i].GetBookname()<<" "<<book[i].GetISBN()<<" "<<book[i].GetAuthorname()<<" "<<book[i].GetDividename()<<endl;
		}
	}
};
#endif

