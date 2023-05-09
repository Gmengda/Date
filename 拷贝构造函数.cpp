#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//¹¹Ôìº¯Êý
class Date
{
public:
	Date(int year = 1000, int mounth = 1, int date = 1)
	{
		cout << 123123 << endl;
		_year = year;
		_mounth = mounth;
		_date = date;
	}

	Date(const Date& m)
	{
		cout << 123123 << endl;
		_year = m._year;
		_mounth = m._mounth;
		_date = m._date;
	}

	~Date()
	{
		cout << 321321 << endl;
	}
	int _year;
	int _mounth;
	int _date;
};

int main()
{
	Date M(2023,10,3);
	Date M2(M);

	cout << M2._date << endl;
	return 0;
}