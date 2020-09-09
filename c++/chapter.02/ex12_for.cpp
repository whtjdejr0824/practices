#include<iostream>
using namespace std;

int main() {
    
    int sum = 0;
    for(int i=0; i<=10; i++) {
        sum += i;
    }
    cout << "1부터 10까지 정수의 합 = " << sum << endl;
    cout <<i; //지역변수 범위에 대한 에러

    {
        int a = 10;
        cout << a;
    }
    cout << a; //지역변수 범위에 대한 에러
    return 0;
}