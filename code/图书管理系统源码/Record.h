#ifndef RECORD_H
#define RECORD_H
#include <bits/stdc++.h>
using namespace std;
class Record
{
	public:
		Record()//¼ÇÂ¼ 
		{
			Bookname="";
			ISBN="";
			Authorname="";
			Dividename="";
		}
		void dispaly()
		{
			cout<<Bookname<<" "<<ISBN<<" "<<Authorname<<" "<<Dividename<<" "<<endl;
		}
		void Sethistory(string a,string b,string c,string d);
	protected:
	string Bookname;
	string ISBN;
	string Authorname;
	string Dividename;
};

#endif
