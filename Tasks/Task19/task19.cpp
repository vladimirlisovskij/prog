//
// Created by vladimir on 22.10.2019.
//
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    int all_nums[10] = {};
    cin >> n;
    for (int i =0; i <n; i++){
        int num;
        cin >> num;
        all_nums[num] ++;
    }
    for (int i = 0; i < 10; i++) if (all_nums[i]) cout << i << ':' << all_nums[i] << endl;
    return 0;
}