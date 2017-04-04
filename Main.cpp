#include "MyString.h"

void test_string()
{
    MyString str1 = "";
    cout << str1.empty() << endl;

    MyString str2 = "Anapopo";
    cout << str2.count() << endl;

    cout << str2 << endl;
}

int main()
{
    MyString str1 = "opoppopo";
    MyString str2 = "nameisgood";
    cout << str1.isTwisted() << endl;
    cout << str2.isTwisted() << endl;
    return 0;
}
