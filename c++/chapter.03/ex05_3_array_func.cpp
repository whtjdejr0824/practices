#include<iostream>
using namespace std;

// int array[]={1, 2, 3,....};
void initArray(int array[], int value = 0) {
// ?int size = sizeof(array) / sizeof(int); // 배열의 길이 구하기

    for(int i=0; i < size ; i++) {
        array[i] = value;
    }

}

void printArray(int array[]) {
    for(int i=0, i < size ; i++) {
        cout << array[i] << ", ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int intList[15];

    initArray(initList,15, 100); //100으로 초기화
    printArray(initList, 15);
    
    initArray(initList, 15) ;    //0으로 초기화
    printArray(initList, 15);
    
    return 0;
}