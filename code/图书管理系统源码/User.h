#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
#include "Record.h"
using namespace std;
class User:public Record
{
protected:
	int Borrownum=0;//������ 
	int Returnnum=0;//������ 
	long long int account;//�˺� 
	string password;//���� 
	Record Borrowrecord[500];//�����¼ 
	Record Returnrecord[500];//�����¼ 
public:
//	static int num;//�û����� 
	User()
	{
		password="123456";//��ʼ������  �˺������������� 
	}
	void Setaccount(long long int);//������˺�  
	long long int Getaccount();//�õ��Լ��˺� 
	string Getpassword();//�õ��Լ����� 
	void Changepassword(string a);//�޸����� 
	void SetBorrowHistory(string a,string b,string c,string d);//��ӽ�����ʷ 
	void SetReturnHistory(string a,string b,string c,string d);//��ӻ�����ʷ 
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
