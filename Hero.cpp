#include "Hero.h"
#include "JSON.h"
#include <iostream>

Hero::Hero(const std::string &name, const int health, const int damage, const double atkcooldown, const double defense,
           const int ExperiencePerLevel, const int HealthPointBonusPerLevel, const int DamageBonusPerLevel, const double ColdownMultiplierPerLevel, const double DefenseBonusPerLevel)
    : Monster{name, health, damage, atkcooldown, defense}, maxHealth(health), ExperiencePerLevel(ExperiencePerLevel), HealthPointBonusPerLevel(HealthPointBonusPerLevel),
      DamageBonusPerLevel(DamageBonusPerLevel), ColdownMultiplierPerLevel(ColdownMultiplierPerLevel), DefenseBonusPerLevel(DefenseBonusPerLevel)
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
    damage += DamageBonusPerLevel;
    atkcooldown *= ColdownMultiplierPerLevel;
    maxHealth += HealthPointBonusPerLevel;
    health = maxHealth;
}

void Hero::Attack(Monster &enemy)
{
    Monster::Attack(enemy);

    if (enemy.isAlive())
    {
        while (level - 1 != (xp / ExperiencePerLevel))
        {
            LevelUp();
        }
    }

    xp += damage;
}

Hero Hero::parse(const std::string &fileName)
{
    JSON data = JSON::parseFromFile(fileName);

    return Hero(
        data.get<std::string>("name"),
        data.get<int>("base_health_points"),
        data.get<int>("base_damage"),
        data.get<double>("base_attack_cooldown"),
        data.get<double>("defense"),
        data.get<int>("experience_per_level"),
        data.get<int>("health_point_bonus_per_level"),
        data.get<int>("damage_bonus_per_level"),
        data.get<double>("cooldown_multiplier_per_level"),
        data.get<double>("defense_bonus_per_level"));
}