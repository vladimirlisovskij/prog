//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

int fact(int a){
    if (!a) return  1;
    else return a * fact(a-1);
    
}

int main(){
    int a;
    cin >> a;

    cout << fact(a);

    return 0;
}
