#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace mm
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const mm::string& s);
        friend istream& operator>>(istream& _cin, mm::string& s);
    public:
        typedef char* iterator;
    public:
        string(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        string(const string& s)
        {
            _size = s._size;
            _capacity = s._capacity;
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
        }
        string& operator=(const string& s)
        {
            _size = s._size;
            _capacity = s._capacity;
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
        }
        ~string()
        {
            delete[] _str;
            _size = 0;
            _capacity = 0;
            _str = nullptr;
        }
        //////////////////////////////////////////////////////////////
        // iterator
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        /////////////////////////////////////////////////////////////
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        // modify

        void push_back(char c)
        {
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            }
            _str[_size] = c;
            _str[++_size] = '\0';
        }

        string& operator+=(char c)
        {
            push_back(c);
            return *this;
        }

        void append(const char* str)
        {
            int len = strlen(str);
            reserve(_size + len + 1);
            strcpy(_str + _size, str);
            _size += len;
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str()const
        {
            return _str;
        }

        /////////////////////////////////////////////////////////////
        // capacity
        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            return _size == 0 ? true : false;
        }

        void resize(size_t n, char c = '\0')
        {

        }

        
        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index)             //可读可写 很随意
        {
            assert(index < _size);
            return _str[index];
        }

        const char& operator[](size_t index)const  //只读不写 看字符串内容
        {
            assert(index < _size);
            return _str[index];
        }
        /////////////////////////////////////////////////////////////

        //relational operators

        bool operator<(const string& s) const
        {
            int ret =  memcmp(_str, s._str,s._size < _size ? s._size : _size);
            return ret == 0 ? _size < s._size : ret < 0;
        }

        bool operator<=(const string& s) const
        {
            return (*this < s) || (*this == s);
        }

        bool operator>(const string& s) const
        {
            return !(*this <= s);
        }

        bool operator>=(const string& s) const
        {
            return !(*this < s);
        }

        bool operator==(const string& s) const
        {
            return (_size == s._size) && memcpy(_str, s._str, _size);
        }

        bool operator!=(const string& s) const
        {
            return !(*this == s);
        }

        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const
        {

        }
        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const
        {

        }
        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c)
        {

        }
        string& insert(size_t pos, const char* str)
        {

        }
        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len)
        {

        }
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };
};



ostream& operator<<(ostream& _cout, const mm::string& s)
{

};
istream& operator>>(istream& _cin, mm::string& s)
{

};




