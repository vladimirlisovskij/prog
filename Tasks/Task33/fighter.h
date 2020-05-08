#ifndef WORKS_FIGHTER_H
#define WORKS_FIGHTER_H

#include <random>

class Fighter {
public:
    Fighter(int health_points, int force_points, int critical_points, int defence_points, int agility_points);
    Fighter();

    bool add_health_points(int points);
    bool add_force_points(int points);
    bool add_defence_points(int points);
    bool add_agility_points(int points);
    bool add_critical_points(int points);
    double damage(double dmg);
    double attack();
    bool is_dead();

private:
    double force();
    bool critical();
    double defence();
    bool agility();

    double _health_points;
    double _health;
    double _force_points;
    double _defence_points;
    double _agility_points;
    double _critical_points;
    double _points;
};

#endif //WORKS_FIGHTER_H