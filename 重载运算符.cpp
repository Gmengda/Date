#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1000, int mounth = 1, int date = 1)
	{
		_year = year;
		_mounth = mounth;
		_date = date;
	}

	Date(const Date& m)
	{

		_year = m._year;
		_mounth = m._mounth;
		_date = m._date;
	}

	bool operator==(const Date& x)
	{
		return _year == x._year && _mounth == x._mounth && _date == x._date;
	}

	~Date()
	{

	}
	int _year;
	int _mounth;
	int _date;
};

int main()
{
	Date d1(2023,5,6);
	Date d2(d1);

	if (d1 == d2)
	{
		cout << 123 << endl;
	}
	if (1 == 1)
	{
		cout << 321 << endl;
	}

	return 0;
}