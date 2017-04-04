#include <iostream>
using namespace std;
class MyString
{
private:
    char *element;
    int length;//堆栈申请的内存长度
    int n;//字符串实际长度
    void init(char *s = "", int length = 32);

public:
    MyString(char *s = "", int length = 32);
    MyString(char ch);
    MyString(MyString &str);
    MyString& operator=(MyString &str);
    MyString& operator=(char *str);
    ~MyString();
    bool empty();
    int count();
    char& operator[](int i);
    friend ostream& operator<<(ostream& out, MyString &str);
    void printPrevious();//反序输出
    void reverse();//将当前串逆转
    int search(MyString &pattern, int start = 0);//BF算法查找模式匹配字符串
    //3-4判断回文序列
    bool isTwisted();
};
//构造函数
void MyString::init(char *s, int length)
{
    this->n = strlen(s);
    this->length = (n * 2) > length ? (n * 2) : length;
    this->element = new char[this->length];
    for (int i = 0; s[i] != '\0'; i++) this->element[i] = s[i];
    this->element[this->n] = '\0';
}
//构造函数
MyString::MyString(char *s, int length) { this->init(s, length); }
//构造函数
MyString::MyString(char ch)
{
    this->init("");
    this->n = 1;
    this->element[0] = ch;
    this->element[1] = '\0';
}
//判断为空否？
bool MyString::empty()
{
    return (this->element[0] == '\0') ? true : false;
}
//返回字符串长度
int MyString::count()
{
    int i = 0;
    while (this->element[i] != '\0') i++;
    return i;
}
//拷贝构造函数，深拷贝
MyString::MyString(MyString &str){ this->init(str.element); }
//重载=赋值运算符，深拷贝
MyString& MyString::operator=(MyString &str)
{
    this->~MyString();
    this->init(str.element);
    return *this;
}
//重载[]运算符
char& MyString::operator[](int i)
{   
    if (i < 0) i = 0;
    if (i >= this->n) i = (this->n - 1);
    return this->element[i];
}
//重载<<输出流运算符
ostream& operator<<(ostream& out, MyString& str)
{
    out << "\"" << str.element << "\"";
    return out;
}
//重载=符号
MyString& MyString::operator=(char *str)
{
    this->~MyString();
    this->init(str);
    return *this;
}
//析构函数
MyString::~MyString(){ delete this->element; }
//反序输出
void MyString::printPrevious()
{   
    for (int i = (n - 1); i >= 0; i--)
        cout << element[i];
    cout << endl;
}
//将当前串逆转
void MyString::reverse()
{
    for (int i = 0; i < this->n / 2; i++)
    {   
        int end = this->n - i - 1;
        char temp = element[end];
        element[end] = element[i];
        element[i] = temp;
    }
}
//BF算法搜索
int MyString::search(MyString &pattern, int start)
{
    int i = start, j = 0;
    while (i < this->n)
    {
        if (this->element[i] == pattern.element[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
        if (j == pattern.n)
            return (i - j);
    }
    return -1;
}
//3-4判断回文序列
bool MyString::isTwisted()
{
    for (int i = 0; i < this->n / 2; i++)
    {
        int end = this->n - i - 1;
        if (element[i] != element[end])
            return false;
    }
    return true;
}