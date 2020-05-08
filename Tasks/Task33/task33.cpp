#include <iostream>
#include <thread>
#include <chrono>

#include "fighter.h"

using namespace std;

Fighter create_fighter() {
    int health_points, force_points, critical_points, defence_points, agility_points;
    cout << "\thealth_points: "; cin >> health_points;
    cout << "\tforce_points: "; cin >> force_points;
    cout << "\tcritical_points: "; cin >> critical_points;
    cout << "\tdefence_points: "; cin >> defence_points;
    cout << "\tagility_points: "; cin >> agility_points;
    return {health_points, force_points, critical_points, defence_points, agility_points};
}

Fighter bot_fighter() {
    Fighter res;
    bool temp = true;
    while (temp) {
        int num = random() % 5;
        switch (num) {
            case 0:
                temp = res.add_health_points(1);
                break;
            case 1:
                temp = res.add_force_points(1);
                break;
            case 2:
                temp = res.add_defence_points(1);
                break;
            case 3:
                temp = res.add_agility_points(1);
                break;
            case 4:
                temp = res.add_critical_points(1);
                break;
        }
    }
    return res;
}

int main(){
    srand(time(NULL));
    int mode;
    cout << "mode\n\t1) bot vs bot\n\t2) player vs bot\n\t3) player vs player\n->\t";
    cin >> mode;
    Fighter player1, player2;
    string lab1, lab2;
    switch (mode) {
        case 1:
            lab1 = "bot 1";
            lab2 = "bot 2";
            cout << "bot vs bot mode\n";
            player1 = bot_fighter();
            player2 = bot_fighter();
            break;
        case 2:
            lab1 = "bot";
            lab2 = "player";
            cout << "bot vs player mode\n";
            cout << lab2 << endl;
            player1 = bot_fighter();
            player2 = create_fighter();
            break;
        case 3:
            lab1 = "player 1";
            lab2 = "player 2";
            cout << "player vs player mode\n";
            cout << lab1 << endl;
            player1 = create_fighter();
            cout << lab2 << endl;
            player2 = create_fighter();
            break;
        default:
            cout << "invalid mode\n";
            return 0;
    }
    while (!(player1.is_dead() || player2.is_dead())) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << lab1 << " received damage of " << player1.damage(player2.attack()) << " units" << endl;
        cout << lab2 << " received damage of " << player2.damage(player1.attack()) << " units"<< endl << endl;
    }
    if (player1.is_dead() && player2.is_dead()) cout << "no winner";
    else cout << (player1.is_dead() ? lab2 : lab1) << " win";
    return 0;
}