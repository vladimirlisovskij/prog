//
// Created by vladimir on 28.09.2019.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b ,x1, x2, d, temp, x_max, x_min, x;

    bool flag = true;

    cin >> a >> b >> x1 >> x2 >> d;  //    0.7 1.2 0.5 1.5 0.05
    cout << "|  " << 'x' << " | " << 'y' << " |" <<  endl << "|-----|-----|" << endl;

    x = x1;
    x_max = 0;
    x_min = 0;

    for (int i = 0; i <= (x2 -x1)/d; i ++, x += d){

        if (x <= a) temp = abs(x);
        else if ((a < x)&& (x < b)) temp = abs(x) + cos(x);
        else if( x >= b) temp = tan(x);

        if (flag) {
            x_max = temp;
            x_min = temp;
            flag = false;
        } else if (temp > x_max) x_max = temp;
        else if (temp < x_min) x_min = temp;

        cout <<  "|  " << x << " | " << temp<< " |" <<  endl;
    }
    cout << endl << "max: " << x_max << "  min: " << x_min << endl;
    return 0;
}