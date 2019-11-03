//
// Created by vladimir on 31.10.2019.
//
#include <iostream>
#include <ctime>
using namespace std;
int main(){
    int array[10][8] = {};
    int row, col, att = 5;
    srand(time(NULL));
//    int* ptr = &array[0][0];
//    int num = rand() % (10 * 8 -1);
//    cout << num << endl;
//    cout << num/10  + 1<< ' ' << num%8 << endl;
//    *(ptr + num) = 1;
    *(&array[0][0] + rand() % (10 * 8 - 1)) = 1;
    while (att){
        cout << endl << "Осталось попыток: " << att << endl;
        cin >> row >> col;
        if ((row < 0) || (row > 9) || (col < 0) || (col > 7)) cout << "Вышли за рамки" << endl;
        else if (array[row][col] == -1) cout << "Не корректный ввод" << endl;
        else if (array[row][col] == 1){
            cout << "Вы победили" << endl;
            break;
        }
        else {
            cout << "Не верный выбор" << endl;
            array[row][col] = -1;
            att--;
        }
    }
    if (!att) cout << "Вы проиграли" << endl;
    return 0;
}