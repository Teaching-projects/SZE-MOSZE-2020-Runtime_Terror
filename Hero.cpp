#include "Hero.h"
#include <iostream>

Hero::Hero(const std::string& name, const int health, const int damage, const float atkcooldown) : Monster{name, health, damage, atkcooldown}, maxHealth(health)
{
}

int Hero::getLevel() const 
{
    return level;
}

int Hero::getXp() const 
{
    return xp;
}

int Hero::getMaxHealthPoints() const 
{
    return maxHealth;
}

void Hero::LevelUp() 
{
    level += 1;
    damage += damage * 0.1;
    maxHealth += maxHealth * 0.1;
    health = maxHealth;
}

void Hero::fightTilDeath(Monster& target) 
{
    Monster::fightTilDeath(target);
    xp += damage;
    while(level - 1 != (xp / 100))
    {
        LevelUp();
    }
}

Hero Hero::parse(const std::string& fileName)
{
    Monster parsedMonster = Monster::parse(fileName);
    return Hero(parsedMonster.getName(), parsedMonster.getHealthPoints(), parsedMonster.getDamage(), parsedMonster.getAttackCoolDown());
}