//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

double UNLIMITED_POWER(double a, int b){
    if (b == 0) return 1;
    else if (b > 0) return a * UNLIMITED_POWER(a, b - 1);
    else return 1 / UNLIMITED_POWER(a, abs(b));
}

int main(){
    double a;
    int b;

    cin >> a >> b;
    if (!a && b < 0) cout << "inf";
    else cout << UNLIMITED_POWER(a, b);

    return 0;
}