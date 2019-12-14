//
// Created by canned_dead on 09.12.2019.
//
#include <iostream>
#include <cstring>

using namespace std;

bool is_ok(char ch, const char* arr, int len){
    for (int i = 0; i < len; i ++){
        if (ch == arr[i]) return true;
    }
    return false;
}

char* strtok2(char* string, const char* delim){
    static int start = 0;
    static int end = 0;
    static char* str = string;
    static int leng = 0;

    if (string != nullptr){
        start = 0;
        end = 0;
        str = string;
        int i = 0;
        while (string[i] != '\0'){
            i ++;
            leng ++;
        }
    }
    while (is_ok(str[start], delim, strlen(delim)) && start < leng){
        start ++;
        end ++;
    }
    if (start >= leng){
        return nullptr;
    } else{
        while (!is_ok(str[end], delim, strlen(delim)) && end < leng){
            end ++;
        }
        int len = end - start;
        char* res = new char [len + 1];
        for (int i = 0; i < len; i ++){
            res[i] = str[i + start];
        }
        res[len] = '\0';
        end ++;
        start = end;
        return res;
    }
}


int main(){
    char* str_buf= new char [100];
    char* delim_buf = new char [100];
    cin.getline(str_buf, 100);
    cin.getline(delim_buf, 100);

    char* temp = strtok2(str_buf, delim_buf);
    int words = 0;
    while (temp != nullptr) {
        cout  << temp << endl;
        temp = strtok2(nullptr, delim_buf);
        words ++;
    }
    cout << "words:" << words << endl;
    return 0;
}