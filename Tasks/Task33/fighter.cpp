#include "fighter.h"

Fighter::Fighter(int health_points, int force_points, int critical_points, int defence_points, int agility_points)
    : _health_points(health_points)
    , _force_points(force_points)
    , _critical_points(critical_points)
    , _defence_points(defence_points)
    , _agility_points(agility_points)
    , _points(0)
    , _health(100+_health_points*100)
{
}

Fighter::Fighter()
    : _health(100)
    , _health_points(0)
    , _force_points(0)
    , _critical_points(0)
    , _defence_points(0)
    , _agility_points(0)
    , _points(10)
{
}

bool Fighter::add_health_points(int points) {
    if (points > _points) return false;
    _points -= points;
    _health_points += points;
    return true;
}

bool Fighter::add_force_points(int points) {
    if (points > _points) return false;
    _points -= points;
    _force_points += points;
    return true;
}

bool Fighter::add_defence_points(int points) {
    if (points > _points) return false;
    _points -= points;
    _defence_points += points;
    return true;
}

bool Fighter::add_agility_points(int points) {
    if (points > _points) return false;
    _points -= points;
    _agility_points += points;
    return true;
}

bool Fighter::add_critical_points(int points) {
    if (points > _points) return false;
    _points -= points;
    _critical_points += points;
    return true;
}

double Fighter::force() {
    return 1 + _force_points;
}

bool Fighter::critical() {
    double rand_int = (random() % RAND_MAX) / (double)RAND_MAX;
    return rand_int >
                            1
        / //---------------------------------------
           (1 + pow(_critical_points/4.0, 4));
}

double Fighter::defence() {
    return
                            1
    / //--------------------------------------
       (1 + pow(_defence_points/4.0, 4));
}

double Fighter::attack() {
    return force() * (1 + critical());
}

bool Fighter::agility() {
    double rand_int = (random() % RAND_MAX) / (double)RAND_MAX;
    return rand_int >
                             1
    / //---------------------------------------
       (1 + pow(_agility_points/4.0, 4));
}

double Fighter::damage(double dmg) {
    double res = (1 - agility()) * defence() * dmg;
    _health -= res;
    return res;
}

bool Fighter::is_dead() {
    return _health <= 0;
}