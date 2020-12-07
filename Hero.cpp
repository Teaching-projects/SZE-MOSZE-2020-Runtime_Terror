#include "Hero.h"
#include "JSON.h"
#include <iostream>

Hero::Hero(const std::string &name, const int health, const int physicalDamage, const int magicalDamage, const double atkcooldown, const int defense,
           const int ExperiencePerLevel, const int HealthPointBonusPerLevel, const int PhysicalDamageBonusPerLevel, const int MagicalDamageBonusPerLevel, const double ColdownMultiplierPerLevel, 
           const int DefenseBonusPerLevel, const int lightRadius, const int LightRadiusBonusPerLevel, const std::string texture)
    : Monster{name, health, physicalDamage, magicalDamage, atkcooldown, defense, texture}, maxHealth(health), ExperiencePerLevel(ExperiencePerLevel), HealthPointBonusPerLevel(HealthPointBonusPerLevel),
      PhysicalDamageBonusPerLevel(PhysicalDamageBonusPerLevel), MagicalDamageBonusPerLevel(MagicalDamageBonusPerLevel), ColdownMultiplierPerLevel(ColdownMultiplierPerLevel), DefenseBonusPerLevel(DefenseBonusPerLevel),
      lightRadius(lightRadius), LightRadiusBonusPerLevel(LightRadiusBonusPerLevel)
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

int Hero::getLightRadius() const
{
    return lightRadius;
}

void Hero::LevelUp()
{
    level += 1;
    damage.physical += PhysicalDamageBonusPerLevel;
    damage.magical += MagicalDamageBonusPerLevel;
    atkcooldown *= ColdownMultiplierPerLevel;
    maxHealth += HealthPointBonusPerLevel;
    health = maxHealth;
    defense += DefenseBonusPerLevel;
    lightRadius += LightRadiusBonusPerLevel;
}

void Hero::Attack(Monster &enemy)
{
    int enemyHealth = enemy.getHealthPoints();    
    Monster::Attack(enemy);

    int xp = 0;
    if (damage.physical - enemy.getDefense() > 0)
    {
        xp += (damage.physical - enemy.getDefense());
    }
    xp += damage.magical;

    if (xp > enemyHealth) 
    {
        this->xp += enemyHealth;
    }
    else
    {
        this->xp += xp;
    }    

    while (level - 1 != (xp / ExperiencePerLevel))
    {
        LevelUp();
    }
}

Hero Hero::parse(const std::string &fileName)
{
    JSON data = JSON::parseFromFile(fileName);

    return Hero(
        data.get<std::string>("name"),
        data.get<int>("base_health_points"),
        data.get<int>("base_damage", 0),
        data.get<int>("magical_damage", 0),
        data.get<double>("base_attack_cooldown"),
        data.get<int>("defense"),
        data.get<int>("experience_per_level"),
        data.get<int>("health_point_bonus_per_level"),
        data.get<int>("damage_bonus_per_level", 0),
        data.get<int>("magical_damage_bonus_per_level", 0),
        data.get<double>("cooldown_multiplier_per_level"),
        data.get<int>("defense_bonus_per_level"),
        data.get<int>("light_radius"),
        data.get<int>("light_radius_bonus_per_level", 1),
        data.get<std::string>("texture"));
}