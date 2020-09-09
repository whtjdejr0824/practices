#include<iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    string list[] = {"apple", "banana", "peach"};

    for(auto& name: list) {
        cout << name << endl;
    }
    return 0;
}