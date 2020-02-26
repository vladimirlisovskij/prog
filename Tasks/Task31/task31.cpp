#include <iostream>
#include <string>
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

bool check(int x, int y) {
    if (x <= ::x_max && x >= ::x_min && y <= ::y_max & y >= y_min) {
        switch (::maze[y][x]) {
            case '#':
                return false;
            case ' ':
                return true;
            default:
                std::cout << ::maze[y][x] << " ";
                return false;
        }
    } else {
        return false;
    }
}


void helper(std::queue<std::pair<int, int>>* que) {
    if (!que->empty()) {  // пока в очереди есть точки
        std::pair<int, int> start = que->front();
        ::maze[start.second][start.first] = '#';
        if (check(start.first - 1, start.second)) que->push(std::pair<int, int>{start.first - 1, start.second});
        if (check(start.first + 1, start.second)) que->push(std::pair<int, int>{start.first + 1, start.second});
        if (check(start.first, start.second - 1)) que->push(std::pair<int, int>{start.first, start.second - 1});
        if (check(start.first, start.second + 1)) que->push(std::pair<int, int>{start.first, start.second + 1});
        que->pop();  // удаляем рассмотренный элемент
        helper(que);
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
        std::queue<std::pair<int, int>> que;
        que.push(start);
        helper(&que);
    }
    return 0;
}