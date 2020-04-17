#include <iostream>
#include <cmath>

using  namespace std;

 int
 main (void)
 {
    double a,b,c;
    cin >> a >> b >> c;
    if (!a) // первый коэф нуль
    {
        (!b ? (!c ? cout << "Бесконечно много решений" : cout << "решений нет") : cout << "X = " << -c / b) << endl;
    }
    else
    {
        double D = b*b - 4*a*c;
        if (D<0)
        {
            cout << "Корней нет" << endl;
        }
        else {
            !D ? cout << "X = " << -b / 2 / a << endl : cout << "X1 = " << (-b + sqrt(D)) / 2 / a << endl << "X1 = "
                                                             << (-b - sqrt(D)) / 2 / a << endl;
        }
    }

    return 0;
}