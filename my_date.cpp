#define _CRT_SECURE_NO_WARNINGS 1
#include "date.h"

void Date::dateprint(Date& d)
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int Date::GetMonthDay(int year, int month)
{
	static int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((month == 2) && ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)))
	{
		return 29;
	}
	return m[month];
}

Date::Date(int year, int month, int day)
{
	_day = day;
	_month = month;
	_year = year;
}

Date::Date(const Date& d)
{
	_day = d._day;
	_month = d._month;
	_year = d._year;
}

Date& Date::operator=(const Date& d)
{
	this->_day = d._day;
	this->_month = d._month;
	this->_year = d._year;
	return *this;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		if (_month == 12)
		{
			_year++;
			_month = 0;
		}
		_month++;
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day < 1)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	return _day == d._day
		&& _month == d._month
		&& _year == d._year;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	if (_year < d._year)
	{
		return false;
	}
	else if (_year == d._year && _month < d._month)
	{
		return false;
	}
	else if (_year == d._year && _month < d._month && _day < d._day)
	{
		return false;
	}
	return true;
}

// >=运算符重载
bool Date::operator >= (const Date& d)
{
	return !(*this < d);
}

// <运算符重载
bool Date::operator < (const Date& d)
{
	return !(*this == d || *this > d);
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	int Year = _year;
	int Month = _month;
	int Day = _day;
	int sum = 0;
	while (Year > d._year)
	{
		Year--;
		if ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0))
		{
			sum += 366;
		}
		else
		{
			sum += 365;
		}
	}

	while (Month > d._month)
	{
		sum += GetMonthDay(Year, Month);
		Month--;
	}
	
	while (Month < d._month)
	{
		sum -= GetMonthDay(Year, Month);
		Month++;
	}
	
	if (Day > d._day)
	{
		sum += (Day - d._day);
	}
	else
	{
		sum -= (d._day - Day);
	}
	

	return sum;
}

// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}