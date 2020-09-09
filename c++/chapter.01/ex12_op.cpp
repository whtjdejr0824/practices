#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    int x = 100;
    int y = 200;

    int result = x + y;
    cout << "X + Y : " << result << endl;
    cout << "X - Y : " << x- y << endl;
    cout << "X / Y : " << x /(double)y << endl; //type cast (새로운 타입)
    cout << "X % 3 : " << x %3 << endl;
    cout << "1/2 : " << endl; //정수/정수 -->정수(몫)
    cout << "1/2. : " << endl; //정수/실수 -->실수
    return 0;

}