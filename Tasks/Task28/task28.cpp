//
// Created by canned_dead on 04.12.2019.
//
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool is_sort(int* arr, int len){
    for (int i = 1; i < len; i++){
        if (arr[i - 1] < arr [i]){
            return false;
        }
    }
    return  true;
}

bool is_sort(vector<int> arr, int len){
    for (int i = 1; i < len; i++){
        if (arr[i - 1] < arr [i]){
            return false;
        }
    }
    return  true;
}

void Bozo_sort(int* arr, int len){
    cout << "BOZO ARR" << endl;
    while (!is_sort(arr, len)) {
        int index1 = rand() % len;
        int index2 = rand() % (len - 1);
        if (index2 >= index1) index2++;
        swap(arr[index1], arr[index2]);

        for (int i = 0; i < len; i++) cout << arr[i] << ' ';
        cout << endl;
    }
}

void Bozo_sort(vector<int> &arr){
    cout << "BOZO VECTOR" << endl;
    int len = arr.size();
    while (!is_sort(arr, len)) {
        int index1 = rand() % len;
        int index2 = rand() % (len - 1);
        if (index2 >= index1) index2++;
        swap(arr[index1], arr[index2]);

        for (int i = 0; i < len; i++) cout << arr[i] << ' ';
        cout << endl;
    }
}

int* random_num (int* a, int* b, int* c, int index){
    switch (index) {
        case 0:
            return a;
        case 1:
            return b;
        case 2:
            return c;
    }
}

void Bozo_sort(int* a, int* b, int* c){
    cout << "BOZO a b c" << endl;
    while (!((*a >= *b) && (*b >= *c))) {
        int index1 = rand() % 3;
        int index2 = rand() % 2;
        if (index2 >= index1) index2++;
        swap(*random_num(a, b, c, index1),
             *random_num(a, b, c, index2));

        cout << *a << *b << *c << endl;
    }
}

int main(){
    srand(time(NULL));
    int n;

    cin >> n;

    if (n == 3){
        int a,b,c;
        cin >> a >> b >> c;
        Bozo_sort(&a, &b, &c);
        int arr[] = {a,b,c};
        Bozo_sort(arr, 3);
        vector<int> arr2 ={a, b, c};
        Bozo_sort(arr2);
    } else {
        int *arr = new int[n];

        vector<int> arr2;
        arr2.resize(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            arr2[i] = arr[i];
        }

        Bozo_sort(arr, n);
        Bozo_sort(arr2);


        delete[] arr;
    }
    return 0;
}