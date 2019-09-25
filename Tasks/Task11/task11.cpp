//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

int fact(int a, int res = 1){
    if (a == 1) return  res;
    else return fact(a-1, res*a);
    
}

int main(){
    int a;
    cin >> a;

    cout << fact(a);

    return 0;
}
