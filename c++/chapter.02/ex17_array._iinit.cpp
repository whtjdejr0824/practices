#include<iostream>
using namespace std;

int main() {
    const int STUDENTS = 5;

    int scores[STUDENTS] = {
        0, // 전체 데이터를 0으로 바꾸고자 할때,
        // 100, 200, 300, 400, 500 // , 600 // 엘리먼트 개수가 많은 경우는 syntax error
    };

    int sum = 0;
    int i;
    double averge;

    for(i=0; i<STUDENTS; i++) {
        sum += scores[i];
    }

    averge = sum / (double)STUDENTS;
    cout << "성적 평균=" << averge << endl;

    return 0;
}