#include<iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string s = "When in Roma, do as the Romas.";

    // 읽기
    for(auto& ch: s) { // char &ch = s[i] 속도가 빠름
        cout << ch << ' ';
    }
    cout << endl;

    for(auto ch: s) { // char ch = s[i]
        cout << ch << ' ';
    }
    cout << endl;

    // 쓰기(원본복사 유무)
    for(auto& ch: s) { // char &ch = s[i]
        ch = 'T';
    }
    cout << s << endl;

    for(auto ch: s) { // char ch = s[i] 
        ch = 'W';
    }
    cout << s << endl;

    return 0;
}