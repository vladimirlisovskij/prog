//
// Created by vladimir on 18.11.2019.
//
#include <iostream>
#include <cstring>

using namespace std;

char* get_cstring(int buf_size){
    char* buf = new char [buf_size];
    cin.getline(buf, buf_size);
    return buf;
}


size_t strlen2(const char* string){
    size_t size = 0;
    for (int i = 0; string[i] != '\0'; i++) size++;
    return size;
}


int strcmp2(const char* string1, const char* string2 ){
    size_t string1_size = strlen2(string1);
    size_t string2_size = strlen2(string2);
    for (int i = 0; i < min(string1_size, string2_size) + 1; i++)
        if (string1[i] != string2[i]) return (string1[i] > string2[i]) ? 1 : -1;
    return 0;
}


int* prefix_len(char* string, int string_len){
    int* res = new int [string_len];

    for (int max_pref_len = 1; max_pref_len <= string_len; max_pref_len++)
        for (int pref_len = 1; pref_len < max_pref_len; pref_len++){
            int str_len = max_pref_len - pref_len;
            bool flag = true;

            for (int i =0; i < pref_len; i++)
                if (string[i] != string[i + str_len]){
                    flag = false;
                    break;
                }
            if (flag) res[max_pref_len-1] = pref_len;
        }

    return res;
}


char* strstr2(char* string1, char* string2){ // поиск Кнута Морриса Пратта
    int str1_size = strlen2(string1);
    int str2_size = strlen2(string2);
    int* pref = prefix_len(string2, str2_size);
    int res = 0;

    for (int max_indx =0; max_indx <= str1_size - str2_size; max_indx++){
        bool flag = true;

        for (int i = 0, j = max_indx; i < str2_size; i++, j++){
            res = j;

            if (string1[j] != string2[i]){
                max_indx += pref[i];
                flag = false;
                break;
            }
        }
        if (flag){
            delete[] pref;
            return  &(string1[res - str2_size + 1]);
        }
    }

    delete[] pref;
    return 0;
}


char* strcat2(char* destptr, const char* srcptr){
    int str1_size = strlen2(destptr);
    int str_size2 = strlen2(srcptr);

    for (int i = str1_size, j =0; i < str1_size + str_size2 ; i++, j++) destptr[i] = srcptr[j];

    destptr[str1_size + str_size2] = '\0';

    return destptr;
}


int main(){
    int max_str_size = 100;
    char* string1 = get_cstring(max_str_size);
    char* string2 = get_cstring(max_str_size);

    int len1 = strlen2(string1), len2 = strlen2(string2);

    cout << len1 << ' ' << len2 << endl;

    int res = strcmp2(string1, string2);
    if(!res) cout << "Строки равны" << endl;
    else cout << ((res > 0) ? "Первая" : "Вторая") << " строка больше" << endl;



    if (!strstr2(string1, string2)) cout << "ничего не найдено"  << endl;
    else cout << string1 - strstr2(string1, string2) << endl;

    cout << strcat2(string1, string2) << endl;

    cout << string1 << endl;

    delete[] string1, string2;
    return 0;
}