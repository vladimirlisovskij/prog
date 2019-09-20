//
// Created by vladimir on 20.09.2019.
//

#include <iostream>

using namespace std;

int main() {
    double a,b;
    char c;
    cin >> a >> c >> b;
    switch (c){
        case '/':
            if (b == 0) {
                cout << "Деление на ноль!" << endl;
            } else {
                cout << a / b << endl;
            }
            break;
        case '-':
            cout << a -b << endl;
            break;
        case '+':
            cout << a + b << endl;
            break;
        case '*':
            cout << a*b << endl;
            break;
        default:
            cout << "Введите корректный оператор!" << endl;
    }
    return 0;
}