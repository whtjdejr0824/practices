#pragma once

#include <string>
using namespace std;

// 클래스원형
class PrintData {

public:
    void print(int i);
    void print(double f);
    void print(string s = "NO Data!");
};