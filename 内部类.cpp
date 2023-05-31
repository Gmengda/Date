#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


class A
{
public:

	void funca()
	{

	}
	class B
	{
		void funcb(const A& a)
		{
			cout << a._a << endl;
		}
	private:
		int b;
	};

private:
	int _a;
};


int main()
{

	return 0;
}



