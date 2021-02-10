#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
#include "Record.h"
using namespace std;
class User:public Record
{
protected:
	int Borrownum=0;//借书量 
	int Returnnum=0;//还书量 
	long long int account;//账号 
	string password;//密码 
	Record Borrowrecord[500];//借书记录 
	Record Returnrecord[500];//还书记录 
public:
//	static int num;//用户总数 
	User()
	{
		password="123456";//初始化密码  账号在主函数设置 
	}
	void Setaccount(long long int);//添加新账号  
	long long int Getaccount();//得到自己账号 
	string Getpassword();//得到自己密码 
	void Changepassword(string a);//修改密码 
	void SetBorrowHistory(string a,string b,string c,string d);//添加借书历史 
	void SetReturnHistory(string a,string b,string c,string d);//添加还书历史 
	void displayHistory()
	{
		for(int i=0;i<Borrownum;i++)
		{
			Borrowrecord[i].dispaly();
		}
	} 
	void displayHistory1()
	{
		for(int i=0;i<Returnnum;i++)
		{
			Returnrecord[i].dispaly();
		}
	 } 
	 int GetReturnnum();
	int GetBorrownum();
};
//int User:: num=0;
#endif
