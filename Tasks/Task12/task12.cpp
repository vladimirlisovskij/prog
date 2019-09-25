//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

int main(){
    int a;
    cin >> a;

    int b[a];

    for (int i =0; i < a; i ++){
        b[i] = i+1;
    }

    for (int i = 1; i <a; i++){
        if (b[i] != 0){
            for (int j = b[i]*2; j <= a; j += b[i]){
                b[j-1] = 0;
            }
        }
    }

    /*for (int i = 0; i <a; i ++){
        cout << b[i];
    }*/

    cout << ((b[a-1] != 0) ? "Простое" : "Не простое");



    return 0;
}