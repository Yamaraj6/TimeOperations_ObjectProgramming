#include "Date.h"
#include "TimeStamp.h"
#include <limits>
using namespace std;
int main()
{
	//ULLONG_MAX
	//long long double a=12345678901234567289834;
//	cout << a;
	Date date(2222, 1, 1);
	Date date2(2000, 5, 13);
	cout<<date.DaysBetweenDates(date2)<<endl;
	date.vPrintDate();
	Date *date3=(date - 21);
	cout << endl;
	date3->vPrintDate();
	cout << endl << (*date3 >= date)<<endl;

	TimeStamp a(200870390);
	TimeStamp b(34);
	TimeStamp c = TimeStamp(2017, 01, 27, 10, 27);
	TimeStamp d = TimeStamp(2017, 02, 3, 15, 0);
	c.vPrintTime();
	d.vPrintTime();
	cout<<c.iMinutesBetween(d)/60<<endl;
	cout << (a < b) << endl;
	(a - 253)->vPrintDate();cout << endl;
	(a - 253)->vPrintTime();
	system ("PAUSE");
	
}