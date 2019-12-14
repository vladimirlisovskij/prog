//
// Created by canned_dead on 12.12.2019.
//
#include <iostream>
#include <ostream>
#include <string>

#include "libbmp.h"

int main() {
    BmpImg img;

    img.read ("pic3.bmp");

    std::cout << int(img.blue_at(0,0));

    return 0;
}
