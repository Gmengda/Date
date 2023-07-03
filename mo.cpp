template<typename T>  // 模板参数 -- 类型
void Swap(T& x1, T& x2)
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}

int main()
{
	int a = 0, b = 1;
	double c = 1.1, d = 2.2;
	//Swap(a, b);
	//Swap(c, d);
	swap(a, b);
	swap(c, d);

	int* p1 = &a, *p2 = &b;
	swap(p1, p2);



	//Date d1(2023,5,12), d2(2023, 1, 1);

	return 0;
}