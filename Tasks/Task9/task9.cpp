//
// Created by vladimir on 25.09.2019.
//

#include <iostream>
#include <ctime>

using  namespace std;

int main(){
    bool ans = true;
    bool m;
    int ans2;
    srand(time(NULL));

    while (ans) {
        int num = rand() % 100;
        //cout<< num << endl;
        m = false;
        for (int i = 0; i <5; i++) {
            cin >> ans2;
            if (ans2 < num) cout << "Заданное число больше" << endl;
            else if (ans2 > num) cout << "Заданное чилсло меньше" << endl;
            else {
                cout << "Поздравляю! Вы угадали" << endl;
                m = true;
                break;
            }
        }
        if (!m) cout << "Вы проиграли. Было загадано: " << num << endl;
        cout << "Хотите начать сначала? (1 - ДА )" << endl;
        cin >> ans2;
        ans = ans2 == 1 ? true : false;
    }
    return 0;
}