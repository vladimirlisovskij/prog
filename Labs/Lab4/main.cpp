//
// Created by canned_dead on 08.12.2019.
//
#include "helper.h"
#include <iostream>
#include <ctime>

int main(){
    std::srand(std::time(NULL));
    char player;
    while (player != 'X' && player != 'O' && player != '0'){
        std::cout << "Ввыберите символ" << std::endl;
        std::cin >> player;
    }
    game::Game game1 = game::initGame('X');
    if (game1.isUserTurn) {
        while (true) {
            game::userTurn(&game1);
            game::updateDisplay(game1);
            if (game::updateGame(&game1)) break;
            game::botTurn(&game1);
            game::updateDisplay(game1);
            if (game::updateGame(&game1)) break;
        }
    } else{
        while (true) {
            game::botTurn(&game1);
            game::updateDisplay(game1);
            if (game::updateGame(&game1)) break;
            game::userTurn(&game1);
            game::updateDisplay(game1);
            if (game::updateGame(&game1)) break;
        }
    }
    switch (game1.status){
        case game::USER_WIN:
            std::cout << "Вы победили";
            break;
        case game::BOT_WIN:
            std::cout << "Вы проиграли";
            break;
        case game::NOT_WIN:
            std::cout << "Ничья";
            break;
    }
    std::cout << std::endl;
}


