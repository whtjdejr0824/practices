#include<iostream>
using namespace std;

int main() {
    const int STUDENTS = 10;

    int scores[STUDENTS];
    int sum = 0;
    int i, averge;

    for(i=0; i<STUDENTS; i++) {
      cout << "학생들의 성적을 입력하시오: ";
      cin >> scores[i];
    }

    for(i=0; i<STUDENTS; i++) {
        sum += scores[i];
    }

    averge = sum / STUDENTS;
    cout << "성적 평균= " << averge << endl;
    return 0;
}