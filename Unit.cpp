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

Unit::Unit(const std::string name, const int health, const int damage, const float atkcooldown) : name(name), health(health), damage(damage), atkcooldown(atkcooldown)
{
    currentcooldown = atkcooldown;
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

float Unit::GetCurrentCooldown() const
{
    return currentcooldown;
}

void Unit::Attack(Unit &target)
{
    target.SufferDamage(damage);
    target.LowerCooldown(currentcooldown);
    ResetCooldown();
}

void Unit::SufferDamage(int damageRecieved)
{
    health -= damageRecieved;
    if (health < 0)
    {
        health = 0;
    }
}

Unit Unit::parseUnit(const std::string &fileName)
{
    std::map<std::string, std::string> data = Json::ParseFile(fileName);
    Unit u = Unit(data["name"], std::stoi(data["hp"]), std::stoi(data["dmg"]), std::stoi(data["attackcooldown"]));
    return u;
}