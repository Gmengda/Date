//class A
//{
//public:
//	/*explicit A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}*/
//	
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1);
//	A aa2 = 2; // 隐式类型转换，整形转换成自定义类型]
//	// 2构造一个A的临时对象，临时对象再拷贝构造aa2 -->优化用2直接构造
//
//	// error C2440: “初始化”: 无法从“int”转换为“A &”
//	//A& aa3 = 2;
//	const A& aa3 = 2;
//
//
//	int i = 10;
//	double d = i;
//
//	return 0;
//}

//class string
//{
//public:
//	string(const char* str)
//	{}
//};

//class list
//{
//public:
//	void push_back(const string& str)
//	{}
//};
//
//int main()
//{
//	string name1("张三");
//	string name2 = "张三";
//
//	list lt1;
//	string name3("李四");
//	lt1.push_back(name3);
//
//	lt1.push_back("李四");
//
//	return 0;
//}

//int _scount = 0;
//
//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	~A() { --_scount; }
//	/*static int GetACount() { return _scount; }*/
//private:
//	/*static int _scount;*/
//};
//
//A aa0;
//
//void Func()
//{
//	static A aa2;
//	cout << __LINE__ << ":" << _scount << endl;
//
//	// 全局变量的劣势：任何地方都可以随意改变
//	_scount++;
//}
//
//int main()
//{
//	cout <<__LINE__<<":"<< _scount << endl;  // 1
//	A aa1;
//	
//	Func();  // 3
//	Func();  // 3
//
//	return 0;
//}

//class A
//{
//public:
//	A() 
//	{
//		++_scount;
//	}
//
//	A(const A& t) 
//	{
//		++_scount;
//	}
//
//	~A() 
//	{ 
//		--_scount;
//	}
//
//
//	void Func1()
//	{
//		// 非静态能否调用静态：可以
//		GetACount();
//	}
//
//	void Func2()
//	{
//		++_a1;
//	}
//
//	// 没有this指针，指定类域和访问限定符就可以访问
//	static int GetACount() 
//	{ 
//		// 静态能否调用非静态：不可以。非静态的成员函数调用需要this指针，我没有this
//		// Func2();
//
//		//_a1++;
//		return _scount;
//	}
//private:
//	// 成员变量 -- 属于每个一个类对象，存储对象里面
//	int _a1 = 1;
//	int _a2 = 2;
////public:
//	// 静态成员变量 -- 属于类，属于类的每个对象共享，存储在静态区
//	static int _scount;
//};
//
//// 全局位置，类外面定义
//int A::_scount = 0;
//
//A aa0;
//
//void Func()
//{
//	static A aa2;
//	cout << __LINE__ << ":" << aa2.GetACount() << endl;
//
//	// 全局变量的劣势：任何地方都可以随意改变
//	//_scount++;
//}
//
//int main()
//{
//	cout <<__LINE__<<":"<< A::GetACount() << endl;  // 1
//	A aa1;
//	
//	Func();  // 3
//	Func();  // 3
//
//	return 0;
//}

// 设计一个类，在类外面只能在栈上创建对象
// 设计一个类，在类外面只能在堆上创建对象
class A
{
public:
	static A GetStackObj()
	{
		A aa;
		return aa;
	}

	static A* GetHeapObj()
	{
		return new A;
	}
private:
	A()
	{}

private:
	int _a1 = 1;
	int _a2 = 2;
};

int main()
{
	//static A aa1;   //  静态区
	//A aa2;          //  栈 
	//A* ptr = new A; //  堆
	A::GetStackObj();
	A::GetHeapObj();

	return 0;
}