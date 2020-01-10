//
// Created by canned_dead on 12.12.2019.
//
#include <iostream>
#include <ostream>
#include <cmath>

#include "libbmp.h"

enum canal{
    BLUE,
    GREEN,
    RED
};

char to_char(bool arr [8]){
    int sum = 0;
    for (int i = 0; i < 8; i ++){
        sum += std::pow(2, i) * arr[i];
    }
    char res = sum;
    return res;
}

bool get_bit (int x, int y, BmpImg img){
    static int len = 0;
    int color_num;
    static canal color = BLUE;
    static bool temp [8] = {};

    switch (color){
        case RED:
            color_num = int(img.red_at(x,y))%2;
            break;
        case GREEN:
            color_num = int(img.green_at(x,y))%2;
            break;
        case BLUE:
            color_num = int(img.blue_at(x,y))%2;
            break;
    }
    temp[7 - len] = color_num;
    len ++;

    if (len == 8){
        char temp_char = to_char(temp);
        if (temp_char == char(0)){
            std::cout << std::endl;
            len = 0;
            color = static_cast<canal> ((color + 1)%3);
            return false;
        }else{
            std::cout << temp_char;
            len = 0;
            color = static_cast<canal> ((color + 1)%3);
            return true;
        }
    }
    color = static_cast<canal> ((color + 1)%3);
    return true;
}

int main() {
    BmpImg img; img.read ("pic10.bmp");

    const int y_max = img.get_height();
    const int x_max = img.get_width();

    for (int y_pos = 0; y_pos < y_max; y_pos ++){
        for (int x_pos = 0; x_pos < x_max; x_pos ++){
//            std::cout << std::endl << x_pos << ' ' << y_pos << std::endl;
            if (!get_bit(x_pos, y_pos, img)) return 0;
            if (!get_bit(x_pos, y_pos, img)) return 0;
            if (!get_bit(x_pos, y_pos, img)) return 0;
        }
    }
    return 0;
}