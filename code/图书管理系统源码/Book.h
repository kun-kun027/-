#ifndef BOOK_H
#define BOOK_H
#include <bits/stdc++.h>
using namespace std;
class Book
{
protected:
	static int num;//书籍总数设置为静态成员 
	string Bookname;
	string ISBN;
	string Authorname;
	string Dividename;
	bool flag;//1表示书未被借走，0表示书被借走 
public:
	Book()//默认构造函数 
	{
		Bookname="";
		Authorname="";
		ISBN="";
		Dividename="";
		flag=1;
	}
	void SetBookname(string a);//因为是数组所以采用用成员函数 
	void SetAuthorname(string a);
	void SetISBN(string a);
	void SetDividename(string a);
	string  GetBookname();
	string  GetAuthorname();
	string  GetISBN();
	string  GetDividename();
	void  Addnum();//书的数量随管理员删除增添而变化 
	void Deletenum(); 
	void  Borrowbook();//借书 改变书的状态 
	void Returnbook();//还书 
	bool returnflag();//得到书借还的状态 
	int Getnum();
};

#endif
