//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

void  func(int * arr, int num, int steps = 5){
    for (int i = 0; i < steps; i++){
        if (num < *(arr +i)) {
            swap(num, *(arr +i));
        }
    }
    if (steps < 5)  arr[steps] = num;
}

void out(int * arr, int num = 4){
    for (num; num >=0; num--){
        cout << *(arr + num) << ' ';
    }
    cout << endl;
}


int main(){
    int a, temp;
    int * b = new int [5];

    cin >> a;

    for  (int i = 0; i < a; i++){
        cin >> temp;
        if (i == 0) {
            b[0] = temp;
            out (b, i);
        }
        else if (i < 5) {
            func(b, temp, i);
            out (b, i);

        }
        else {
            func(b, temp);
            out (b);
        }

        cout << endl;
    }

     delete[](b);

    return 0;
}