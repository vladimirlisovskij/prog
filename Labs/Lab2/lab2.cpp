//
// Created by vladimir on 28.09.2019.
//

#include <iostream>
#include <cmath>

using namespace std;

double z1(double x){
    return (abs(x));
}

double z2(double x){
    return (abs(x)) + cos(x);
}

double z3(double x){
    return (tan(x));
}


int main(){
    double a, b ,x1, x2, d, temp, x_max, x_min, x;

    bool flag = true;

    x_max = 0;
    x_min = 0;

    cin >> a >> b >> x1 >> x2 >> d;
//    0.7 1.2 0.5 1.5 0.05
    cout << "|  " << 'x' << " | " << 'y' << " |" <<  endl << "|-----|-----|" << endl;

    for (int i = 0; i <= (x2 -x1)/d; i ++){
        x = x1 + (d*i);
        if (x <= a) {
            temp = z1(x);
            if (flag) {
                x_max = temp;
                x_min = temp;
                flag = false;
            }
        }
        else if ((a < x)&& (x < b)) {
            temp = z2(x);
            if (flag) {
                x_max = temp;
                x_min = temp;
                flag = false;
            }
        }
        else if( x >= b){
            temp = z3(x);
            if (flag) {
                x_max = temp;
                x_min = temp;
                flag = false;
            }
        }

        if (temp > x_max) x_max = temp;
        if (temp < x_min) x_min = temp;

        cout <<  "|  " << x << " | " << temp<< " |" <<  endl;
    }
    cout << endl << "max: " << x_max << "  min: " << x_min << endl;
    return 0;
}
