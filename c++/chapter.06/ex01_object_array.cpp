#include <iostream>
using namespace std;

class Circle {
public:
  int x, y;
  int radius;

  Circle(): x(0), y(0), radius(0) {}
  Circle(int x, int y, int r): x(x), y(y), radius(r) {}
  void print() {
      cout << "radius : " << radius << "@(" << x << "," << y << ")" << endl;  
  }
};

int main() {
    Circle objArray[10]; // 10개의 요소가 디폴트 생성자에 의해 생성

    for(Circle c : objArray) { // 초기화가 어떻게 되었는지 확인
        c.print();
    }
    cout << "----------" << endl;
    for(Circle& c: objArray) { 
        c.x = rand()%500;
        c.y = rand()%300;
        c.radius = rand()%100;
    }

    for(Circle c : objArray) {
        c.print();
    }

    cout << "-----------" <<endl;
    // cout << "Circle mamory size : " <<sizeof() << endl;
    // cout << "length " <<sizeof() << endl;
    return 0;
}