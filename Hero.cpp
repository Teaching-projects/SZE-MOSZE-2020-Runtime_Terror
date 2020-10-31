#include "Hero.h"
#include "JSON.h"
#include <iostream>

Hero::Hero(const std::string& name, const int health, const int damage, const float atkcooldown, 
    const int ExperiencePerLevel, const int HealthPointBonusPerLevel, const int DamageBonusPerLevel, const float ColdownMultiplierPerLevel) 
    : Monster{name, health, damage, atkcooldown}, maxHealth(health), ExperiencePerLevel(ExperiencePerLevel), HealthPointBonusPerLevel(HealthPointBonusPerLevel), 
    DamageBonusPerLevel(DamageBonusPerLevel), ColdownMultiplierPerLevel(ColdownMultiplierPerLevel)
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
   JSON data = JSON::parseFromFile(fileName);
    
    return Hero(
        data.get<std::string>("name"),
        data.get<int>("base_health_points"),
        data.get<int>("base_damage"),
        data.get<float>("base_attack_cooldown"),
        data.get<int>("experience_per_level"),
        data.get<int>("health_point_bonus_per_level"),
        data.get<int>("damage_bonus_per_level"),
        data.get<float>("cooldown_multiplier_per_level")
    );
}