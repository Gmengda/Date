// F.h #include 
using namespace std; 
inline void f(int i); 

// F.cpp 
#include "F.h" 
void f(int i) 
{
     cout << i << endl; 
} 

// main.cpp 
#include "F.h" 
int main() 
{
     f(10);
     return 0; 
}
// 链接错误：main.obj : error LNK2019: 无法解析的外部符号 "void __cdecl f(int)" (?f@@YAXH@Z)，该符号在函数 _main 中被引用