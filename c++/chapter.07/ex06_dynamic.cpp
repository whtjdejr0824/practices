#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Dog {
public :
  int age;
  string name;
  Dog() {
      cout << "Dog constructor call" << endl;
      age = 1;
      name = "happy";
}
  ~Dog() {
      cout << "Dog deconstructor call" << endl;
  }
};

int main() {
    unique_ptr<Dog> dog(new Dog);
    // Dog *pDog = new Dog;
    // delete pDog; // 지우거나 참고할 경우 memory leak(메모리 누수)
    return 0;
} 