#include "Unit.h"
#include <string>

bool Unit::IsDead() const
{
    return health <= 0;
}

Unit::Unit(const std::string name, const int health, const int damage) : name(name), health(health), damage(damage)
{
}

void Unit::Attack(Unit &target) const
{
    target.health -= damage;
    if (target.health < 0)
        target.health = 0;
}