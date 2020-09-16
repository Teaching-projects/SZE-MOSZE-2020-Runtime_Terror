#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Unit {
    public:
    Unit(std::string, int, int);
    std::string name;
    int health;
    int damage;
    bool IsDead();
    void Attack(Unit&);
};

#endif