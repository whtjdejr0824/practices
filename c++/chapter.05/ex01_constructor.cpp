#include<iostream>
using namespace std;

class Second {
public:
  int sec;
  
  Second() {
      sec = 0;
  }

  Second(int s) {
      sec = s;
  }
};
//Second second; // 디폴트 생성자
//Second second(20); // 매개변수 1개인 생성자(생성자가 매개변수인데 디폴트 생성자가 없어서)
class Time {
public:
    int hour;
    int minute;
    Second sec;

// 생성자
// Time(int h, int m) {
//     hour = h;
//     minute = m;
//     }

Time() : sec(20) { // Second sec(20); 과 같음
    hour = 0;
    minute = 0;
    // sec.Secend = 20; // sec 인스턴스가 만들어진 이후에 하는 작업임.
    }

Time(int h, int m) : hour(h), minute(m) { // int hour(h); int minute(m);

}
void print() {
    cout << hour << ":" << minute << endl;
    }
};

// call by value
void printTime(Time t) { // Time &t(call by refernce), Time * time(call by address)
    cout << "Time => " << t.hour << ":" << t.minute << endl;
}

int main() {
//   Time a; // 디폴트 생성자를 사용하기
  Time b(10, 25); //(int, int) 생성자 없음
  Time c{10, 25};
  Time d= {10, 25};

  // 정적 객체(할당)일 때 = 연산은 복사 입니다.
  c = b; // 파이썬 : 참조, c++ : 복사
  c.hour = 3;

  printTime(b);
  printTime(c);
  b.print();
  c.print();
  d.print();
}