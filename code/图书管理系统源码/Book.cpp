#include "Book.h"
void Book:: SetBookname(string a)
{
	Bookname=a;
}
void Book::SetAuthorname(string a)
{
	Authorname=a;		
}
void Book::SetISBN(string a)
{
	ISBN=a;
}
void Book::SetDividename(string a)
{
	Dividename=a;
}
string Book::GetBookname()
{
	return Bookname;
}
string Book::GetAuthorname()
{
	return Authorname;
}
string Book::GetISBN()
{
	return ISBN;
}
string Book:: GetDividename()
{
	return Dividename;
}
int Book::num=0;
 int Book:: Getnum()
{
	return num;
}
 
void Book:: Borrowbook()
{
	flag=0;
}
void Book::Returnbook()
{
	flag=1;
}
bool Book::returnflag()
{
	return flag;
}
void Book::Addnum()
{
	num++;
 } 
 void Book::Deletenum()
 {
 	num--;
 }
