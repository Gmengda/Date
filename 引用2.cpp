struct List
{
    int arr[100];
    int size;
}

int& ListGet(struct List& arr,int pos)
{
    assert(pos < 100);
    assert(arr);
    return arr.arr[pos];
}

void TestConstRef() 
{
    const int a = 10;
    //引用过程中  权限不能放大  存在赋值问题
    //           但是可以平移，缩小
    //int& ra = a;   // 该语句编译时会出错，a为常量
    const int& ra = a;

    // int& b = 10;  // 该语句编译时会出错，b为常量
    const int& b = 10;

    double d = 12.34;
    //int& rd = d;  // 该语句编译时会出错，类型不同
    const int& rd = d; 
    //原因是double 隐式转换成 int 类型时候会产生临时变量，产生的临时变量具有常性
}

int main()
{
    List s;
    //一个函数可以完成读写功能！！
     ListGet(s,0) = 1;
   cout<<ListGet(s,0)<<endl;
   ListGet(s,0) += 5;
   cout<<ListGet(s,0)<<endl;
     return 0;
}