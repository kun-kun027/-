#ifndef BOOK_H
#define BOOK_H
#include <bits/stdc++.h>
using namespace std;
class Book
{
protected:
	static int num;//�鼮��������Ϊ��̬��Ա 
	string Bookname;
	string ISBN;
	string Authorname;
	string Dividename;
	bool flag;//1��ʾ��δ�����ߣ�0��ʾ�鱻���� 
public:
	Book()//Ĭ�Ϲ��캯�� 
	{
		Bookname="";
		Authorname="";
		ISBN="";
		Dividename="";
		flag=1;
	}
	void SetBookname(string a);//��Ϊ���������Բ����ó�Ա���� 
	void SetAuthorname(string a);
	void SetISBN(string a);
	void SetDividename(string a);
	string  GetBookname();
	string  GetAuthorname();
	string  GetISBN();
	string  GetDividename();
	void  Addnum();//������������Աɾ��������仯 
	void Deletenum(); 
	void  Borrowbook();//���� �ı����״̬ 
	void Returnbook();//���� 
	bool returnflag();//�õ���軹��״̬ 
	int Getnum();
};

#endif
