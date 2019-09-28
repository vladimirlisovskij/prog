//
// Created by vladimir on 25.09.2019.
//

#include <iostream>

using namespace std;

int main(){
    long long s, l1, r1, l2, r2;

    cin >> s >> l1 >> r1 >> l2 >> r2;

    long long res1, res2;
    bool stop = false;

    for (int i = l1; i <= r1; i++){
        for (int j = l2; j <= r2; j++){
            // cout << i + j << endl;
            if (i + j == s){
                res1 = i;
                res2 = j;
                stop = true;
                break;
            } else if (i + j > s) break;
        }
        if (stop) break;
    }

    if (stop) cout << res1 << ' ' << res2 << endl;
    else cout << -1;

    return 0;
}