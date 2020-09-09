#include<iostream>
using namespace std;

void print(string char * t) { // *t = 'A'; <-안한다...
    cout << t << endl;
}

int main(int argc, char const *argv[]) {
    char test[] = "Hello"; //문자열 배열(지역변수 : 정적할당)
    char *pstr = "C++";  // 문자열 포인터(지역변수 : 정적할당(8byte))
    string str = "World";  // string 객체

    // cout << test << endl;

    // *pstr = 'P'; //에러
    // cout << pstr << endl;
    // cout << str << endl;
    print(test);
    print(pstr);
    print(str.c_str()); // const char * 리턴   
    return 0;
}