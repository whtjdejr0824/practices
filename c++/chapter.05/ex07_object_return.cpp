#include <iostream>
using namespace std;

class Pizza {
public:
  int size;
  Pizza(int s) : size(s) {}
};

Pizza makePizza() {
    Pizza p(20);
    return p;
}

int main() {
    Pizza pizza = makePizza();

    cout << pizza.size << "inch pizza" << endl;

    return 0;
}