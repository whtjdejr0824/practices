#include<iostream>
#include<string>
using namespace std;

class Circle {
public:
// private:
    int radius; // ¹İÁö¸§
// public:
    string color; // »ı¼º
    
    double calcArea() { // Pythonê³? ?‹¬ë¦? self ë§¤ê°œ ë³??ˆ˜ ?—†?Œ
        return 3.14 * radius * radius; // ë©¤ë²„ ë³??ˆ˜ ? ‘ê·¼ì‹œ ë°”ë¡œ ?‚¬?š©
        }
};

int main(int argc, char const *argv[]){
    Circle pizza1, pizza2; // °´Ã¼ »ı¼º

    pizza1.radius = 100;
    pizza1.color = "yellow";
    cout << "ÇÇÀÚÀÇ ¸éÀû" << pizza1.calcArea() << endl;
    
    pizza2.radius = 200;
    pizza2.color = "yellow";
    cout << "ÇÇÀÚÀÇ ¸éÀû" << pizza1.calcArea() << endl;
    
    return 0;
}
