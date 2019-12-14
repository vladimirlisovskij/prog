//
// Created by vladimir on 05.11.2019.
//
#include <iostream>

using namespace std;

void swap2(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int msort(int* num1, int* num2, int* num3){
    if (*num1 > *num3) swap2(num1, num3);
    if (*num1 > *num2) swap2(num1, num2);
    if (*num2 > *num3) swap2(num2, num3);
    return *num3;
}

void info(const int* num){
    cout << num << " : " << *num << endl;
}

int* add(int* num1, const int* num2){
    (*num1) += (*num2);
    return  num1;
}

int main(){
    int a=1, b=2, c=3;
    info(&a); info(&b); info(&c);
    cout << msort(&a, &b, &c) << endl;
    info(add(add(&a, &b), &c));
    return 0;
}