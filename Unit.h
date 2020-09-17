#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Unit
{
public:
    Unit(const std::string, const int, const int);
    const std::string name;
    int health;
    const int damage;

    bool IsDead() const;
    void Attack(Unit &) const;
};

#endif