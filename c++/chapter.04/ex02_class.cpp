#include<iostream>
#include<string>
using namespace std;

class Circle {
public:
// private:
    int radius; // ������
// public:
    string color; // ����
    
    double calcArea() { // Python�? ?���? self 매개 �??�� ?��?��
        return 3.14 * radius * radius; // 멤버 �??�� ?��근시 바로 ?��?��
        }
};

int main(int argc, char const *argv[]){
    Circle pizza1, pizza2; // ��ü ����

    pizza1.radius = 100;
    pizza1.color = "yellow";
    cout << "������ ����" << pizza1.calcArea() << endl;
    
    pizza2.radius = 200;
    pizza2.color = "yellow";
    cout << "������ ����" << pizza1.calcArea() << endl;
    
    return 0;
}
