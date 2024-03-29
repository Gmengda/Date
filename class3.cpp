class Date {  public:      // 1.无参构造函数      Date()     {}        // 2.带参构造函数      Date(int year, int month, int day)     {          _year = year;         _month = month;          _day = day;     }  private:      int _year;      int _month;      int _day; };void TestDate() {      Date d1; // 调用无参构造函数      Date d2(2015, 1, 1); // 调用带参的构造函数        // 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明      // 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象      // warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)      Date d3(); }


class Date 
{  
public:
 /*
 // 如果用户显式定义了构造函数，编译器将不再生成
 Date(int year, int month, int day)
 { 
    _year = year;
    _month = month; 
    _day = day; 
 }
 */ 
 void Print()
 {
 cout << _year << "-" << _month << "-" << _day << endl;
 }    
private:
 int _year;
 int _month;
 int _day; 
};    

int main() 
{ 
    // 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函 数 
    // 将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再 生成      
    // 无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用 
    Date d1; 
    return 0; 
}