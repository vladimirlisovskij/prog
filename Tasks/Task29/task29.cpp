//
// Created by vladimir on 29.11.2019.
//
#include <iostream>
#include <cstring>


using namespace std;


int main(int argc, char** argv){
    for (int i = 0; i < argc; i++){
        if (!strcmp("-help", argv[i])){
            cout << "flags -n -b -w" << endl;
            return 0;
        }
    }

    bool n = false;
    char* name;
    bool b = false;
    bool w = false;
    char* name2;

    for (int i = 0; i < argc; i++){
        if (!strcmp("-n", argv[i])) {
            if (i != argc - 1) {
                n = true;
                name = argv[++i];
            }else{
                cout << "ERROR" << endl;
                return  1;
            }
        }else if (!strcmp("-b", argv[i])) {
            b = true;
        }else if (!strcmp("-w", argv[i])){
            if (i != argc - 1) {
                w = true;
                name2 = argv[++i];
            }
        }
    }
    if (n || w){
        cout << (b? "BB ":"HELLo ") << (w? name2 : name) << endl;
    }

    return 0;
}