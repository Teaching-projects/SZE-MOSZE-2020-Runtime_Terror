#include "Unit.h"
#include <string>

bool Unit::IsDead() const
{
    return health <= 0;
}

Unit::Unit(const std::string name, const int health, const int damage) : name(name), health(health), damage(damage)
{
}

std::string Unit::GetName() const 
{
    return name;
}

int Unit::GetHealth() const 
{
    return health;
}

int Unit::GetDamage() const 
{
    return damage;
}

void Unit::Attack(Unit &target) const
{
    target.SufferDamage(damage);
}

void Unit::SufferDamage(int damageRecieved)
{
    health -= damageRecieved;
    if(health < 0) {
        health = 0;
    }
}