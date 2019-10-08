//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

int main(){
    int a, res, temp;

    cin >> a;

    for (res = 0, temp = 1; temp <= a; res++, temp *= 2);

    cout << res;

    return 0;
}