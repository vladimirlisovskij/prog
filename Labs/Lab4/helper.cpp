//
// Created by canned_dead on 08.12.2019.
//
#include "helper.h"

#include <cstdlib>
#include <iostream>

namespace game {
    Game initGame(char userChar) {
        Game res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.bord[i][j] = ' ';
            }
        }

        res.isUserTurn = bool(std::rand() % 3);

        res.userChar = userChar;
        switch (res.userChar) {
            case 'O':
                res.botChar = 'X';
                break;
            case 'X':
                res.botChar = 'O';
                break;
        }
        return res;
    }


    void updateDisplay(const Game game) {
        system("clear");
        std::cout << "0  1  2 " << std::endl;
        std::cout << "----------" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << game.bord[i][j] << "|  ";
            }
            std::cout << i << std::endl << "----------" << std::endl;
        }
    }

    void botTurn(Game *game) {
        bool is_clear = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (game->bord[i][j] != ' ') {
                    is_clear = false;
                    break;
                }
            }
        }
        if (is_clear) {
            game->bord[1][1] = game->botChar;
        } else {
            for (auto & i : game->bord) {
                int val = 0;
                int len = 0;
                bool flag = false;
                for (int j = 0; j < 3; j++) {
                    if (i[j] == game->userChar) {
                        len++;
                    } else if (i[j] != game->botChar) {
                        val = j;
                        flag = true;
                    }
                }
                if ((len == 2) && flag) {
                    i[val] = game->botChar;
                    return;
                }
            }

            for (int i = 0; i < 3; i++) {
                int val = 0;
                int len = 0;
                bool flag = false;
                for (int j = 0; j < 3; j++) {
                    if (game->bord[j][i] == game->userChar) {
                        len++;
                    } else if (game->bord[j][i] != game->botChar) {
                        val = j;
                        flag = true;
                    }
                }
                if ((len == 2) && flag) {
                    game->bord[val][i] = game->botChar;
                    return;
                }
            }

            {
                int val = 0;
                int len = 0;
                bool flag = false;
                for (int i = 0; i < 3; i++) {
                    if (game->bord[i][i] == game->userChar){
                        len++;
                    }else if (game->bord[i][i] != game->botChar) {
                        val = i;
                        flag = true;
                    }
                }
                if ((len == 2) && flag){
                    game->bord[val][val] = game->botChar;
                    return;
                }
            }

            {
                int val = 0;
                int len = 0;
                bool flag = false;
                for (int i = 0; i < 3; i++) {
                    if (game->bord[i][2 -i] == game->userChar){
                        len++;
                    }else  if (game->bord[i][2 - i] != game->botChar) {
                        val = i;
                        flag = true;
                    }
                }
                if ((len == 2) && flag){
                    game->bord[val][2 - val] = game->botChar;
                    return;
                }
            }

            int i = 0;
            int j = 0;
            while (game->bord[i][j] != ' '){
                i = rand() % 3;
                j = rand() % 3;
            }
            game->bord[i][j] = game->botChar;
        }
    }

    void userTurn(Game *game){
        int i = 0,j;
        bool flag_i = true, flag_j = true, flag_all = true;
        while (flag_all) {
            while (flag_i) {
                std::cout << std::endl << "X:  ";
                std::cin >> i;
                if ((i < 0) || (i > 2)) {
                    std::cout << "Введите x корректно" << std::endl;
                } else {
                    flag_i = false;
                }
            }

            while (flag_j) {
                std::cout << std::endl << "Y:  ";
                std::cin >> j;
                if ((j < 0) || (j > 2)) {
                    std::cout << "Введите y корректно" << std::endl;
                } else {
                    flag_j = false;
                }
            }
            if (game->bord[i][j] == ' '){
                flag_all = false;
            }else{
                std::cout << "Не жульничайте" << std::endl;
                flag_i = true;
                flag_j = true;
            }
        }
        game->bord[i][j] = game->userChar;
    }

    bool updateGame(Game *game){
            for (int i = 0; i < 3; i++){
                int len2 = 0;
                int len1 = 0;
                for (int j = 0; j < 3; j++){
                    if (game->bord[i][j] == game->userChar) {
                        len1++;
                    }else if (game->bord[i][j] == game->botChar) {
                        len2++;
                    }
                }
                if ((len1 == 3) || (len2 == 3)){
                    game->status = (len1 == 3?USER_WIN:BOT_WIN);
                    return true;
                }
        }

        for (int i = 0; i < 3; i++){
            int len2 = 0;
            int len1 = 0;
            for (int j = 0; j < 3; j++){
                if (game->bord[j][i] == game->userChar) {
                    len1++;
                }else if (game->bord[j][i] == game->botChar) {
                    len2++;
                }
            }
            if ((len1 == 3) || (len2 == 3)){
                game->status = (len1 == 3?USER_WIN:BOT_WIN);
                return true;
            }
        }

        {
            int len2 = 0;
            int len1 = 0;
            for (int i = 0; i < 3; i++) {
                if (game->bord[i][i] == game->userChar){
                    len1++;
                }else if (game->bord[i][i] == game->botChar){
                    len2++;
                }
            }
            if ((len1 == 3) || (len2 == 3)){
                game->status = (len1 == 3?USER_WIN:BOT_WIN);
                return true;
            }
        }

        {
            int len2 = 0;
            int len1 = 0;
            for (int i = 0; i < 3; i++) {
                if (game->bord[i][2 - i] == game->userChar){
                    len1++;
                }else if (game->bord[i][2 - i] == game->botChar){
                    len2++;
                }
            }
            if ((len1 == 3) || (len2 == 3)){
                game->status = (len1 == 3?USER_WIN:BOT_WIN);
                return true;
            }
        }
        int len = 0;
        for (int i = 0; i < 3; i ++){
            for (int j = 0; j < 3; j ++){
                if (game->bord[i][j] != ' '){
                    len ++;
                }
            }
        }
        if (len == 9) {
            game->status=NOT_WIN;
            return true;
        }
        game->status=PLAY;
        return false;
    }
}