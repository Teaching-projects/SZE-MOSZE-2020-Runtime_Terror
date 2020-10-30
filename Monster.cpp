#include "Monster.h"
#include "JSON.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

bool Monster::isAlive() const
{
    return health > 0;
}

Monster::Monster(const std::string name, const int health, const int damage, const float atkcooldown) : name(name), health(health), damage(damage), atkcooldown(atkcooldown)
{
    currentcooldown = atkcooldown;
}

std::string Monster::getName() const
{
    return name;
}

int Monster::getHealthPoints() const
{
    return health;
}

int Monster::getDamage() const
{
    return damage;
}

float Monster::getAttackCoolDown() const
{
    return currentcooldown;
}

void Monster::fightTilDeath(Monster &target)
{
    target.SufferDamage(damage);
    target.LowerCooldown(currentcooldown);
    ResetCooldown();
}
void Monster::ResetCooldown()
{
    currentcooldown = atkcooldown;
}
void Monster::LowerCooldown(float amount)
{
    currentcooldown -= amount;
    if (currentcooldown < 0)
    {
        currentcooldown = 0;
    }
}
void Monster::SufferDamage(int damageRecieved)
{
    health -= damageRecieved;
    if (health < 0)
    {
        health = 0;
    }
}

Monster Monster::parse(const std::string &fileName)
{
    JSON data = JSON::parseFromFile(fileName);
    return Monster(data.get<std::string>("name"), data.get<int>("health_points"), data.get<int>("damage"), data.get<float>("attack_cooldown"));
}