//
// Created by vladimir on 24.11.2019.
//
#include <iostream>
#include <ctime>
#include <cstring>


using namespace std;


const int buf_size = 100;
const int sec_size = 5;


struct Student{
    char name [::buf_size];
    int group;
    int sec [::sec_size];
};


void get_people(Student* res){
    cin.ignore();
    cin.getline(res->name, ::buf_size);
    cin >> res->group;
    for (int i = 0; i < ::sec_size; i++) cin >> res->sec[i];
}


void bubble_sort (Student* arr, int size){
    for (int unsort_size = size; unsort_size; unsort_size--)
        for (int ind1 = 1, ind2 = 0; ind1 < unsort_size; ind1++, ind2++)
            if (strcmp(arr[ind2].name, arr[ind1].name) > 0) swap(arr[ind2], arr[ind1]);
}


bool is_za4et(int* arr){
    for (int i = 0; i < ::sec_size; i++) if (arr[i] > 2) return true;
    return false;
}


void print_student(Student people){
    cout << people.name << endl;
    cout << '\t' << people.group << endl;
    cout << '\t';
    for (int i = 0; i < ::sec_size; i++) cout << people.sec[i] << '\t';
    cout << endl;
}


int main(){
    srand(time(NULL));

    int num;
    cin >> num;

    Student* peoples = new Student [num];
    for (int i = 0; i < num; i++) get_people(&peoples[i]);
    bubble_sort(peoples, num);

    bool flag = true;
    for (int i = 0; i < num; i++) if (is_za4et(peoples[i].sec)){
        print_student(peoples[i]);
        flag = false;
    }
    if (flag) cout << "Все отчислены" << endl;

    delete[](peoples);
    return 0;
}
