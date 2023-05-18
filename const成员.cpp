#define _CRT_SECURE_NO_WARNINGS 1
#include <ostream>
using namespace std;

class Date
{
	//友元函数也可以解决 获取不到成员变量的问题 
	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(ostream& in, Date& d);
public:



	//流插入不能写成成员函数
	//因为默认 Date 对象为第一个参数 变成了左操作数
	//写出来之后就是
	//d1  <<  cout;
	//不符合操作习惯，违背祖师爷
	/*void operator<<(ostream& out)
	{
		out << _year << _month << _date << endl;
	}*/
	//但是写到全局，通过函数重载就可以解决问题

	int Getyear()
	{
		return _year;
	}
	int Getmonth()
	{
		return _month;
	}
	int Getdate()
	{
		return _date;
	}

private:
	int _year;
	int _month;
	int _date;
};

//这种只能写
// cout << d1;
//void operator<<(ostream& out, Date& d)
//{
//	out << d.Getyear() << d.Getmonth() << d.Getdate() << endl;
//}

//这种方法可以写
//cout << d1 << d2 << d3;
ostream& operator<<(ostream& out, Date& d)
{
	out << d.Getyear() << d.Getmonth() << d.Getdate() << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._date >>endl;
	return in;
}
