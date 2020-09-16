#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Unit {
    public:
    Unit(std::string, int, int);
    const std::string name;
    int health;
    const int damage;
    const bool IsDead();
    const void Attack(Unit&);
};

#endif