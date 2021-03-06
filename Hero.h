/**
 * \class Hero
 * 
 * \brief Hero class inherited from Monster class
 * The Hero is a Monster, but it has experience points and level value.
 * In case of a level up, the damage, cooldown, defense, health and max health values are changing.
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/11/02 10:45
*/

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Monster.h"

class Hero : public Monster
{
public:
    Hero(const std::string &, const int, const int, const int, const double, const int, const int, const int, const int, const int, const double, const int, const int, const int, const std::string); ///< Constructor of Hero class

    int getLevel() const;           ///< This is a simple getter function for level value
    int getXp() const;              ///< This is a simple getter function for xp value
    int getMaxHealthPoints() const; ///< This is a simple getter function for the maxHealth value
    int getLightRadius() const;     ///< This is a simple getter function for the ligth radius

    /**
     * \brief Damages target Moster using the Moster's SufferDamage function, increasing the xp and calling the LevelUp() function in case of level up
    */
    void Attack(Monster & /** [in] The Monster the attack is targeting*/);
    static Hero parse(const std::string &);

    virtual ~Hero() {};

private:
    int xp = 0;                             ///< The experience points of a Hero
    int level = 1;                          ///< The level of a Hero
    int maxHealth;                          ///< The maximum health value of a Hero
    const int ExperiencePerLevel;           ///< The experience points needed to level up
    const int HealthPointBonusPerLevel;     ///< The bonus health points in case of a level up
    const int PhysicalDamageBonusPerLevel;  ///< The damage bonus in case of a level up
    const int MagicalDamageBonusPerLevel;   ///< The damage bonus in case of a level up
    const double ColdownMultiplierPerLevel; ///< The cooldown multiplier in case of a level up
    const int DefenseBonusPerLevel;         ///< The defense value increment after level up

    int lightRadius;                        ///< The light radius of the hero
    const int LightRadiusBonusPerLevel;     ///< The light radius bonus in case of a level up

    /**
     * \brief Increasing the Hero's level, maxHealth, damage and defense, multiplying the cooldown; and setting the health value to maxHealth
    */
    void LevelUp();
};

#endif