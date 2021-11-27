//
// Created by aminjonshermatov on 11/7/2021.
//

#include "MyStringIdentifier.h"

using namespace std;

void TestMyString() {
    MyString str;
    str.push_back('1');
    cout << "size:\t" << str.size() << ", capacity:\t" << str.capacity() << '\n';
    str.push_back('2');
    cout << "size:\t" << str.size() << ", capacity:\t" << str.capacity() << '\n';
    str.push_back('3');
    cout << "size:\t" << str.size() << ", capacity:\t" << str.capacity() << '\n';
    str.push_back('4');
    cout << "size:\t" << str.size() << ", capacity:\t" << str.capacity() << '\n';
    str.push_back('5');
    cout << "size:\t" << str.size() << ", capacity:\t" << str.capacity() << '\n';
    str.push_back('6');
    cout << "size:\t" << str.size() << ", capacity:\t" << str.capacity() << '\n';
    str.push_back('7');
    cout << "size:\t" << str.size() << ", capacity:\t" << str.capacity() << '\n';

    cout << "str:\t" << str << '\n';

    MyString str2(str);
    cout << "str2:\t" << str2 << '\n';

    cout << "str < str2:\t" << (str < str2) << '\n';
    cout << "str == str2:\t" << (str == str2) << '\n';
    cout << "str > str2:\t" << (str > str2) << '\n';

    MyString str3(str);
    str3[2] = '4';
    cout << "str3:\t" << str3 << '\n';
    cout << "str < str3:\t" << (str < str3) << '\n';
    cout << "str == str3:\t" << (str == str3) << '\n';
    cout << "str > str3:\t" << (str > str3) << '\n';

    MyString str4(str);
    str4[2] = '2';
    cout << "str4:\t" << str4 << '\n';;
    cout << "str < str4:\t" << (str < str4) << '\n';
    cout << "str == str4:\t" << (str == str4) << '\n';
    cout << "str > str4:\t" << (str > str4) << '\n';
}

void TestStringIdentifier() {
    MyStringIdentifier msi;
    msi.push_back('a');
    msi.push_back('2');
    msi.push_back('3');
    cout << "valid:\t" << msi << '\n';

    MyStringIdentifier msi2;
    msi2.push_back('1');
    msi2.push_back('2');
    msi2.push_back('3');
    cout << "valid:\t" << msi2 << '\n';
}

int main() try {
    TestMyString();
//    TestStringIdentifier();
} catch (exception& ex) {
    cerr << "Exception occurred:\t" << ex.what() << '\n';
}