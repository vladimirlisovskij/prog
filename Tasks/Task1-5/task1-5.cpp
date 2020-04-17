#include <iostream>

using namespace std;

int
main (void)
{
    // первая задача
    cout << "Первая задача" << endl;
    cout << "Реезультат вычисления 2 + 2 * 2 = " << 2 + 2 * 2 << endl;

    // вторая задача
    cout << "Вторая задача" << endl;
    int a = 3, b = 3.999;

    double a2 = 3, b2 = 3.14;

    cout << a << endl << b << endl << a2 << endl << b2 << endl;

    // третья задача
    cout << "Третья задача" << endl;
    int q,w;
    double q2, w2;
    cin >> q >> w >> q2 >> w2;
    cout << "int; int  " << q + w << ' ' << q - w << ' ' << q*w << ' '  << q/w << endl;
    cout << "double; double  " << q2 + w2 << ' ' << q2 - w2 << ' ' << q2*w2 << ' ' << q2/w2 << endl;
    cout << "int; double  " << q + w2 << ' ' << q - w2 << ' ' << q*w2 << ' ' << q/w2 << endl;
    cout << "double; int  "<< q2 + w << ' ' << q2 - w << ' ' << q2*w << ' ' << q2/w << endl;

    // четвертая задача
    cout << "Четвертая задача" << endl;
    int z,x, temp;
    cin >> z >> x;
    x = z;
    z = x;

    cout << z << ' ' << x << endl;
    x = z -x;
    z = z -x;
    x = z + x;

    cout << z << ' ' << x << endl;

    // пятая задача
    cout << "Пятая задача" << endl;
    const double g = -9.8;
    double x0, v0, t0;
    cin >> x0 >> v0 >> t0;
    cout <<x0 + v0*t0 + g*t0*t0/2 << endl;

    return 0;
}