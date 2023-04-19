void TestRef() 
{
   int a = 10;
   // int& ra;   // 该条语句编译时会出错
   int& ra = a;
   int& rra = a;
   printf("%p %p %p\n", &a, &ra, &rra);   
}
void swap(int& a, int& b)//省去写地址，很方便
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(a,b);            //省去写地址，很方便
    return 0;
}