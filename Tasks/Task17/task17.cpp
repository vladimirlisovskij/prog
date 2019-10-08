//
// Created by vladimir on 08.10.2019.
//

#include <iostream>

using namespace std;

double BMI(double weight, double height){
    return weight/(height*height);
}

void printBMI(double BMI){
    if (BMI < 18.5) cout << "Underweight";
    else if ((18.5 <= BMI) && (BMI < 25.0)) cout << "Normal weight";
    else if ((25.0 <= BMI) && (BMI < 30.0)) cout << "Overweight";
    else cout << "Obesity";
}

int main (){
    double w,h;

    cin >> w >> h;

    printBMI(BMI(w,h/100));

    return 0;
}