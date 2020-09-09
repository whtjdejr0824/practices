#include<iostream>
#include <string>
using namespace std;

class Dog {
private :
  int *pAge;
  int * pWeight;

public :
  Dog() {
    pAge = new int{1};
    pWeight = new int{10};
}
~Dog() {
    delete pAge;
    delete pWeight;
}
int getAge(){return *pAge;}
void setAge(int a) {*pAge = a;}
int getWeight(){return *pAge;}
void setWeight(int w) { *pWeight = w;}
};

int main() {
    Dog *pDog = new Dog;
    cout << sizeof(pDog) << endl; // pDog 포인터 변수의 크기
    cout << sizeof(*pDog) << endl; // pDog가 포인트하는 인스턴스의 크기

    cout << "Dog's Age : " << pDog->getAge() <<endl;

    pDog->setAge(3);
    cout << "Dog's Age : " << pDog->getAge() <<endl;

    delete pDog;
    return 0;
}
