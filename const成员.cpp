#define _CRT_SECURE_NO_WARNINGS 1
#include <ostream>
using namespace std;

class Date
{
	//��Ԫ����Ҳ���Խ�� ��ȡ������Ա���������� 
	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(ostream& in, Date& d);
public:



	//�����벻��д�ɳ�Ա����
	//��ΪĬ�� Date ����Ϊ��һ������ ������������
	//д����֮�����
	//d1  <<  cout;
	//�����ϲ���ϰ�ߣ�Υ����ʦү
	/*void operator<<(ostream& out)
	{
		out << _year << _month << _date << endl;
	}*/
	//����д��ȫ�֣�ͨ���������ؾͿ��Խ������

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

//����ֻ��д
// cout << d1;
//void operator<<(ostream& out, Date& d)
//{
//	out << d.Getyear() << d.Getmonth() << d.Getdate() << endl;
//}

//���ַ�������д
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
