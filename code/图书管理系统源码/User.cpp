#include "User.h"
using namespace std;
void User::Setaccount(long long int a)
{
	account=a;
}
long long User::Getaccount()
{
	return account;
}
string User::Getpassword()
{
	return password;
}
void User:: Changepassword(string a)
{
	password=a;
}
void User::SetBorrowHistory(string a,string b,string c,string d)
{
	Borrowrecord[Borrownum].Sethistory(a,b,c,d);
	Borrownum++;
}
void User::SetReturnHistory(string a,string b,string c,string d)
{
	Returnrecord[Returnnum].Sethistory(a,b,c,d);
	Returnnum++;
} 
int User::GetReturnnum()
{
	return Returnnum;
}
int User::GetBorrownum()
{
	return Borrownum;
}

