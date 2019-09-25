//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

double UNLIMITED_POWER(double a, int b, double res = 1){
    if (b == 0){
        return res;
    }else if (b > 0){
        res *= a;
        return UNLIMITED_POWER(a, b-1, res);
    }else{
        res /= a;
        return UNLIMITED_POWER(a, b+1, res);
    }
}

int main(){
    double a;
    int b;

    cin >> a;
    cin >> b;

    cout << UNLIMITED_POWER(a, b);

    return 0;
}