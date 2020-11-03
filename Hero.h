/**
 * \class Hero
 * 
 * \brief Hero class inherited from Monster class
 * The Hero is a Monster, but it has experience points and level value.
 * In case of a level up, the damage, cooldown, health and max health values are changing.
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
    Hero(const std::string&, const int, const int, const float, const int, const int, const int, const float); ///< Constructor of Hero class

    int getLevel() const; ///< This is a simple getter function for level value
    int getXp() const; ///< This is a simple getter function for xp value
    int getMaxHealthPoints() const; ///< This is a simple getter function for the maxHealth value

    /**
     * \brief Damages target Moster using the Moster's SufferDamage function, increasing the xp and calling the LevelUp() function in case of level up
    */
    void Attack(Monster& /** [in] The Monster the attack is targeting*/);
    static Hero parse(const std::string&);

    private:
    int xp = 0; ///< The experience points of a Hero
    int level = 1; ///< The level of a Hero 
    int maxHealth; ///< The maximum health value of a Hero
    const int ExperiencePerLevel; ///< The experience points needed to level up
    const int HealthPointBonusPerLevel; ///< The bonus health points in case of a level up
    const int DamageBonusPerLevel; ///< The damage bonus in case of a level up
    const float ColdownMultiplierPerLevel; ///< The cooldown multiplier in case of a level up

    /**
     * \brief Increasing the Hero's level, maxHealth and damage, multipling the cooldown; and setting the health value to maxHealth
    */
    void LevelUp();
};

#endif