//
// Created by vladimir on 28.11.2019.
//
#include <iostream>


using namespace std;


struct IntArray {
    int* data;
    int size;
};


void create(IntArray* arr, int size){
    arr->data = new int [size];
    arr->size = size;
}


int get(IntArray* arr, int index){
    if (index < 0 && index >= arr->size) throw out_of_range("bad index");
    else return arr->data[index];
}


void set(IntArray* arr, int index, int value){
    if (index < 0 || index >= arr->size) throw out_of_range("bad index");
    else arr->data[index] = value;
}


void print(IntArray* arr){
    cout << '[';
    for (int i = 0; i < arr->size - 1; i++) cout << arr->data[i] << ", ";
    cout << arr->data[arr->size-1] << ']' << endl;
}


void resize(IntArray* arr, int newSize){
    int* new_arr = new int [newSize];
    for (int i = 0; i < min(newSize, arr->size); i++) new_arr[i] = arr->data[i];
    delete[]arr->data;
    arr->data = new_arr;
    if (newSize > arr->size) for (int i = arr->size; i < newSize; i++) arr->data[i] = 0;
    arr->size = newSize;
}


void free(IntArray* arr){
    if (arr->data == 0x0) throw "ptr is null";
    delete[]arr->data;
    arr->data = NULL;
    arr->size = 0;
}


int main(){
    IntArray arr;
    create(&arr, 30);
    for (int i = 0; i < arr.size; i++) set(&arr, i, i);
//    set(&arr, 1000, 10);
    print(&arr);
    resize(&arr, 50);
    print(&arr);
    resize(&arr, 10);
    print(&arr);
    free(&arr);
    free(&arr);

    return 0;
}