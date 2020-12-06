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

Monster::Monster(const std::string name, const int health, const int physicalDamage, const int magicalDamage, const double atkcooldown, const int defense, const std::string texture) 
    : name(name), health(health), damage(Damage(physicalDamage, magicalDamage)), atkcooldown(atkcooldown), defense(defense), texture(texture)
{
}

std::string Monster::getName() const
{
    return name;
}

int Monster::getHealthPoints() const
{
    return health;
}

int Monster::getPhysicalDamage() const
{
    return damage.physical;
}

int Monster::getMagicalDamage() const
{
    return damage.magical;
}

double Monster::getAttackCoolDown() const
{
    return atkcooldown;
}

int Monster::getDefense() const
{
    return defense;
}

std::string Monster::getTexture() const
{
    return texture;
}

void Monster::fightTilDeath(Monster &enemy)
{
    double attackerTime = 0;
    double enemyTime = 0;

    while (this->isAlive() && enemy.isAlive())
    {
        if (attackerTime < enemyTime)
        {
            this->Attack(enemy);
            enemyTime -= attackerTime;
            attackerTime = this->getAttackCoolDown();
        }
        else if (attackerTime > enemyTime)
        {
            enemy.Attack(*this);
            attackerTime -= enemyTime;
            enemyTime = enemy.getAttackCoolDown();
        }
        else
        {
            this->Attack(enemy);
            attackerTime = this->getAttackCoolDown();
            enemyTime = 0;
        }
    }
}

void Monster::Attack(Monster &enemy)
{
    enemy.SufferDamage(this->damage);
}

void Monster::SufferDamage(Damage damageRecieved)
{
    int physicalDamage = damageRecieved.physical - getDefense();
    
    if (physicalDamage < 0) physicalDamage = 0;

    health -= physicalDamage;
    health -= damageRecieved.magical;

    if (health < 0) health = 0;
}

Monster Monster::parse(const std::string &fileName)
{
    JSON data = JSON::parseFromFile(fileName);
    return Monster(
        data.get<std::string>("name"), 
        data.get<int>("health_points"), 
        data.get<int>("damage", 0), 
        data.get<int>("magical_damage", 0), 
        data.get<double>("attack_cooldown"), 
        data.get<int>("defense"),
        data.get<std::string>("texture"));
}