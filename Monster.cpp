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

Monster::Monster(const std::string name, const int health, const int damage, const double atkcooldown) : name(name), health(health), damage(damage), atkcooldown(atkcooldown)
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

int Monster::getDamage() const
{
    return damage;
}

double Monster::getAttackCoolDown() const
{
    return atkcooldown;
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
    return Monster(data.get<std::string>("name"), data.get<int>("health_points"), data.get<int>("damage"), data.get<double>("attack_cooldown"));
}