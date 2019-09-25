//
// Created by vladimir on 25.09.2019.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a;
    cin >> a;
    int res = 0;
    int temp;
    for (int i = 1; i <= a; i++){
        temp = log(i)/log(2);
        if (i - pow(2, temp) == 0) res ++;
    }

    cout << res;

    return 0;
}