#include 
using namespace std; 

// 1、参数类型不同 
int Add(int left, int right) 
{ 
    cout << "int Add(int left, int right)" << endl;
    return left + right; 
} 
double Add(double left, double right) 
{ 
    cout << "double Add(double left, double right)" << endl;
    return left + right; 
} 

// 2、参数个数不同 
void f() 
{ 
    cout << "f()" << endl; 
} 
void f(int a)
{ 
    cout << "f(int a)" << endl; 
}

// 3、参数类型顺序不同 
void f(int a, char b) 
{ 
    cout << "f(int a,char b)" << endl; 
} 
void f(char b, int a) 
{ 
    out << "f(char b, int a)" << endl; 
} 

int main() 
{ 
    Add(10, 20); 
    Add(10.1, 20.2); 
    f(); 
    f(10); 
    f(10, 'a'); 
    f('a', 10); 
    return 0; 
}
//全缺省
void Func(int a = 0,int b = 10) 
{ 
    cout<< a << endl;
    cout<< b << endl;
}

//半缺省
void Func(int a,int b = 10)
{
    cout<< a << endl;
    cout<< b << endl;
}
//1. 半缺省参数必须从右往左依次来给出，不能间隔着给 
//2. 缺省参数不能在函数声明和定义中同时出现
//3. 缺省值必须是常量或者全局变量 
//4. C语言不支持（编译器不支持）
//5. 声明和定义不能同时给缺省！！！  (只能声明给)

int main()
{
    func();    // 没有传参时，使用参数的默认值
    func(1);   // 传参时，使用指定的实参    从左往右传参
    func(1,2);
    func(,3);  //不可以跳越传参
    return 0;
}