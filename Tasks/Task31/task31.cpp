#include <iostream>
#include <string>
#include <set>
#include <queue>

std::string maze[25] = {
        "####B######################",
        "# #       #   #      #    #",
        "# # # ###### #### ####### #",
        "# # # #       #   #       #",
        "#   # # ######### # ##### #",
        "# # # #   #       #     # #",
        "### ### ### ############# #",
        "# #   #     # #           #",
        "# # #   ####### ###########",
        "# # # #       # #         C",
        "# # ##### ### # # ####### #",
        "# # #     ### # #       # #",
        "#   ##### ### # ######### #",
        "######### ### #           #",
        "# ####### ### #############",
        "A           #   ###   #   #",
        "# ############# ### # # # #",
        "# ###       # # ### # # # #",
        "# ######### # # ### # # # F",
        "#       ### # #     # # # #",
        "# ######### # ##### # # # #",
        "# #######   #       #   # #",
        "# ####### ######### #######",
        "#         #########       #",
        "#######E############D######"
};

int x_max = 26, y_max = 24, x_min = 0, y_min = 0;


std::pair<int, int> go_left(int x, int y) {  // идем влево
    while (::maze[y][--x] == ' ') {  // пока не найдем стенку или выход
        if ((y > ::y_min && ::maze[y - 1][x] != '#') || (y < ::y_max && ::maze[y + 1][x] != '#')) {  // если можно свернуть
            ::maze[y][x + 1] = '#';  // что бы не возвращаться
            return std::pair<int, int> {x, y};
        }
    }
    if (::maze[y][x] <= 90 && ::maze[y][x] >= 65) {  // нашли выход
        std::cout << ::maze[y][x];  // вывод выхода
    }
    return std::pair<int, int> {-1, -1};
}


std::pair<int, int> go_right(int x, int y) {
    while (::maze[y][++x] == ' ') {
        if ((y > ::y_min && ::maze[y - 1][x] != '#') || (y < ::y_max && ::maze[y + 1][x] != '#')) {
            ::maze[y][x - 1] = '#';
            return std::pair<int, int> {x, y};
        }
    }
    if (::maze[y][x] <= 90 && ::maze[y][x] >= 65) {
        std::cout << ::maze[y][x];
    }
    return std::pair<int, int> {-1, -1};
}


std::pair<int, int> go_down(int x, int y) {
    while (::maze[--y][x] == ' ') {
        if ((x > ::x_min && ::maze[y][x - 1] != '#') || (x < ::x_max && ::maze[y][x + 1] != '#')) {
            ::maze[y + 1][x] = '#';
            return std::pair<int, int> {x, y};
        }
    }
    if (::maze[y][x] <= 90 && ::maze[y][x] >= 65) {
        std::cout << ::maze[y][x];
    }
    return std::pair<int, int> {-1, -1};
}


std::pair<int, int> go_up(int x, int y) {
    while (::maze[++y][x] == ' ') {
        if ((x > ::x_min && ::maze[y][x - 1] != '#') || (x < ::x_max && ::maze[y][x + 1] != '#')) {
            ::maze[y - 1][x] = '#';
            return std::pair<int, int> {x, y};
        }
    }
    if (::maze[y][x] <= 90 && ::maze[y][x] >= 65) {
        std::cout << ::maze[y][x];
    }
    return std::pair<int, int> {-1, -1};
}


void push(std::queue<std::pair<int, int>>* que, std::pair<int, int> start, std::set<std::pair <int, int>>* passed) {
    if (!passed->count(start)) {  // если точка хорошая и раньше не встречалась
        que->push(start);  // добавляем точку в очередь
        passed->insert(start);  // запоминаем точку
    }
}


void helper(std::queue<std::pair<int, int>>* que, std::set<std::pair <int, int>>* passed) {
    if (!que->empty()) {  // пока в очереди есть точки
        std::pair<int, int> start = que->front();  // выбираем первый элемент
        push(que, go_right(start.first, start.second), passed);  // проходимся в право
        push(que, go_up(start.first, start.second), passed);
        push(que, go_down(start.first, start.second), passed);
        push(que, go_left(start.first, start.second), passed);
        que->pop();  // удаляем рассмотренный элемент
        helper(que, passed);
    }
}


int main() {
    std::pair<int, int> start;
    std::cin >> start.first >> start.second;
    if (::maze[start.second][start.first] == '#' || start.first < ::x_min || start.first > ::x_max ||
        start.second > ::y_max || start.second < ::y_min) {
        std::cout << "ERROR" << std::endl;
    } else if (::maze[start.second][start.first] <= 90 && ::maze[start.second][start.first] >= 65) {
        std::cout << ::maze[start.second][start.first] << std::endl;
    } else {
        std::queue<std::pair<int, int>> que;  // очередь на посещение
        std::set <std::pair<int, int>> passed;  // посещенные точки
        passed.insert(start);
        passed.insert(std::pair<int, int> {-1, -1});  // добавим для проверок на допустимые координаты
        que.push(start);
        helper(&que, &passed);
    }
    return 0;
}