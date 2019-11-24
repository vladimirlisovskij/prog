//
// Created by vladimir on 20.09.2019.
//

#include <iostream>
#include <cmath>

using  namespace std;

double s(double x, double y){
    return sqrt(x*x + y*y);
}
double geron(double p, double a, double b, double c){
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int  main(){
    int m;
    cin >> m;
    if (m == 1){
        double a,b,c;
        cin >> a;
        cin >> b;
        cin >> c;
        if (c <=0 || a <= 0 || b <= 0){
            cout << "Длины сторон должны быть положительными!";
        } if ((a +b < c) && (a + c) < b && (c + b) <a ) cout << "Это не треугольник";
        else {
                cout << "S = " << geron((a + b + c) / 2, a, b, c) << endl;
            }
        }
    else if (m == 2){
        double a1,a2,b1,b2,c1,c2;
        cin >> a1 >> a2;
        cin >> b1 >> b2;
        cin >> c1 >> c2;

        if (((a1 == b1) && (b1 == c1)  && c1 == 0) || (((a2 == b2) && (b2 == c2)  && c2 == 0)) || ((a1/(2*a2+b2+c2) == b1/(a2+2*b2+c2)) && (b1/(a2+2*b2+c2) == c1/(a2+b2+2*c2)))){
            cout << "Введите координаты не лежащие на одной прямой" << endl;
        }else if (((a1 == b1) && (a2 == b2)) || ((a1 == c1) && (a2 == c2)) || ((c1 == b1) && (c2 == b2))) {
            cout << "Точки совпадают" << endl;
        }else {
            double l1 = s(a1 - a2, b1 - b2);
            double l2 = s(b1 - b2, c1 - c2);
            double l3 = s(a1 - a2, c1 - c2);

            cout << "S = " << geron((l1 + l2 + l3) / 2, l1, l2, l3) << endl;
            }
    } else{
        cout << "Введите ключ правильно!" << endl;
    }
    return 0;
}