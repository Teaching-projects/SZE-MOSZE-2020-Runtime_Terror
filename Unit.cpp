#include "Unit.h"
#include "Json.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

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
    if (health < 0)
    {
        health = 0;
    }
}

Unit Unit::parseUnit(const std::string fileName)
{
    std::map<std::string, std::string> data = Json::ParseFile(fileName);

    Unit u = Unit(data["name"], std::stoi(data["hp"]), std::stoi(data["dmg"]));
    return u;
}