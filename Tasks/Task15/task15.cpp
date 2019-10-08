//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

void  func(int * arr, int num, int steps){
    for (int i = 0; i < steps; i++) if (num < *(arr +i)) swap(num, *(arr +i));  // меняем местами переменные
    if (steps < 5)  arr[steps] = num; // ставим переменную в конец
}

void out(int * arr, int num){  // вывод
    for (num; num >=0; num--) cout << *(arr + num) << ' ';
    cout << endl;
}

int main(){
    int a, temp;
    int b [5];

    cin >> a;

    for  (int i = 0; i < a; i++){
        cin >> temp;
        if (i == 0) b[0] = temp;
        else func(b, temp, (i > 5 ? 5 : i));
        out (b, (i > 4 ? 4 : i));
    }

    return 0;
}