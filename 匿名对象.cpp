#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
	{
		_a = a;
		cout << "create A" << endl;
	}

	~A()
	{
		cout << "close A" << endl;
	}
private:
	int _a;
};

class BBB
{
public:
	int num_return(int m)
	{
		return m;
	}
};

int main()
{
	A a(3);

	A(3);   //��������ֻ����һ�У�����������


			//�������Ϊ  ����ת��Ϊ����
			//���ἴ�ü�����
			//���������ӳ�
	const A& aa1 = A(666);

	cout << BBB().num_return(10) << endl;

	return 0;
}