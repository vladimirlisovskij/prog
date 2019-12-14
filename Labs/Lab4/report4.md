МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 4<br/> по дисциплине "Программирование"
<br/>
​
студента 1 курса группы 191(2)  
<br/>Лисовского Владимира Сергеевича  
<br/>направления подготовки 09.03.01 "Информатика и вычислительная техника" 

<br/><br/>
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019

#### Цель

* Закрепить навыки работы с перечислениями;
* Закрепить навыки работы с структурами;
* Освоить методы составления многофайловых программ.

#### Ход работы

1. Вспомогательный файл
    ```cpp
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
                    if (game->bord[i][3 - i] == game->userChar){
                        len1++;
                    }else if (game->bord[i][3 - i] == game->botChar){
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
    ```
2. Файл реализующий игру 
    ```CPP
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
    ```
    
3. Заголовочный файл.
    ```CPP
   //
   // Created by canned_dead on 08.12.2019.
   //
   
   #ifndef WORKS_HELPER_H
   #define WORKS_HELPER_H
   
   namespace game {
       enum Status {
           PLAY,            // Игра продолжается
           USER_WIN,        // Игрок победил
           BOT_WIN,         // Бот победил
           NOT_WIN          // Ничья. Победителя нет, но и на поле нет свободной ячейки
       };
   
       struct Game {
           char bord[3][3];  // Игровое поле
           bool isUserTurn;  // Чей ход. Если пользователя, то isUserTurn = true
           char userChar;    // Символ которым играет пользователь
           char botChar;     // Символ которым играет бот
           Status status;
       };
   
       Game initGame(char);
   
       void updateDisplay(const Game);
   
       void botTurn(Game *);
   
       void userTurn(Game *);
   
       bool updateGame(Game *);
   }
   
   #endif //WORKS_HELPER_H
    ```
   
#### Ввывод

в ходе лабораторной работы были получены такие навыки, как
* умение создавать многофайловые проекты.

