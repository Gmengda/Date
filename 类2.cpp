class Person 
{ 
public: 
    void PrintPersonInfo(); 
private: 
    char _name[20]; 
    char _gender[3]; 
    int  _age; 
}; 

// 这里需要指定PrintPersonInfo是属于Person这个类域 
void Person::PrintPersonInfo() 
{ 
    cout << _name << " "<< _gender << " " << _age << endl;
}

//类的大小计算
class A 
{ 
public: 
    void PrintA() 
    {
       cout<<_a<<endl;
    }
private:
    int a;
    int b;
    char c;1
}