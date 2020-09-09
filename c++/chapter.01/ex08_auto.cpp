#include <iostream>
#include <string>
using namespace std;

auto add(int x, int y) {
    return x + y;
}

int main(int argc, char const *argv[]) {
    auto d = 1.0; // 값을 보고 double 타입이 됨
    // auto d; //auto는 반드시 초기화문과 같이 사용해야 함.
    d = 1.0;

    auto sum =add(5, 10);

    cout <<d<< " " << sum << endl;
    cout <<1.0<<endl;
    return 0; 
}