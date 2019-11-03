//
// Created by vladimir on 23.10.2019.
//
#include <iostream>
#include <string>
using namespace std;
void bubble_sort (int* arr, int size){
    for (int unsort_size = size; unsort_size; unsort_size--)
        for (int ind1 = 1, ind2 = 0; ind1 < unsort_size; ind1++, ind2++)
            if (arr[ind2] > arr[ind1]) swap(arr[ind2], arr[ind1]);
}
int main(){
    int n;
    cin >> n;
    int* arr = new int [n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    delete[] arr;
    return 0;
}