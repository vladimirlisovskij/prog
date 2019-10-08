//
// Created by vladimir on 08.10.2019.
//

#include <iostream>
#include <vector>

using namespace std;

int fac(int n){
    for (int i = 2; i <= n; i++) if (!(n%i)) return i;
    return 1;
}

int main (){
    int num;
    int len = 0;

    vector <vector <int>> nums; // числа и степени

    cin >> num;

    for (int temp = fac(num); temp != 1; num /= temp, temp = fac(num)){
        bool flag = true;

        for (vector<int> &i : nums){
            if (i[0] == temp){
                i[1] ++;
                flag = false;
                break;
            }
        }
        if (flag){
            nums.push_back(vector<int> {temp,0});
            len++;
        }
    }

    if (len) {
        len --;
        for (vector<int> i : nums) {
            cout << i[0];
            if (i[1]) cout << '^' << i[1] + 1;
            if (len) cout << " * ";
            len --;
        }
    } else cout << 1;

    return 0;
}