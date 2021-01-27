#include <iostream>
using namespace std;
struct weather
{
	double temp;
	double wind;
};
int main()
{
	weather today;
	today.temp=10;
	today.wind=33.3;
	cout<<today.temp<<endl<<today.wind; 
	
}
