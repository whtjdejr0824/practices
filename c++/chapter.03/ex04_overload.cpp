#include<iostream>
using namespace std;

int square(int i ) {
    cout << "squre(int) 호출" << endl;
    return i*i;
}

double square(int i ) {
    cout << "squre(double) 호출" << endl;
    return i*i;
}

int main(int argc, char const *argv[])
{
   cout << square(10) << endl;
   cout << square(2.0) << endl;
   return 0;
}
