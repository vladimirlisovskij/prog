//
// Created by vladimir on 15.11.2019.
//
#include <iostream>

using namespace std;

int main(){
    int size = 100;
    char* buf = new char [size];

    cin.getline(buf, size);

    int len = 0;
    for (int i = 0; i < size; i++) {
        if (buf[i] != '\0') len++;
        else break;
    }

    bool flag = true;
    int i = 0, j = len - 1;
    while (j - i > 0){
        char a = tolower(*(buf + i));
        char b = tolower(*(buf + j));
        if (!(isdigit(a) || isalpha(a))){
            i++;
            continue;
        }
        if (!(isdigit(b) || isalpha(b))){
            j--;
            continue;
        }

        i++; j--;
        if (a != b){
            cout << "not";
            flag = false;
            break;
        }
    }

    if (flag) cout << "ok";

    delete[] buf;
    return 0;
}