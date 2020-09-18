#ifndef UNIT_HEADER
#define UNIT_HEADER

#include <string>

class Unit
{
public:
    Unit(const std::string, const int, const int);
    bool IsDead() const;
    void Attack(Unit &) const;
    void SufferDamage(int);

    std::string GetName() const;
    int GetHealth() const;
    int GetDamage() const;

private:
    const std::string name;
    int health;
    const int damage;
};

#endif