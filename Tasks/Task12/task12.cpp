//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

int main(){
    int a;
    bool flag = true;

    cin >> a;

    bool *b = new bool[a];
    for (int i = 2; i < a; i++){
        for (int j = 2*i; j < a; j += i){
            cout << j << endl;
            b[j] == true;
            if (b[a]){
                flag = false;
                cout << "не простое";
                break;
            }
        }
        if (!flag) break;
    }

    delete[] b;
    return 0;
}