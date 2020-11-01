#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Monster.h"

class Hero : public Monster 
{
    public:
    Hero(const std::string&, const int, const int, const float, const int, const int, const int, const float);    

    int getLevel() const;
    int getXp() const;
    int getMaxHealthPoints() const;

    void Attack(Monster&);
    static Hero parse(const std::string&);

    private:
    int xp = 0;
    int level = 1;
    int maxHealth;
    const int ExperiencePerLevel; 
    const int HealthPointBonusPerLevel;
    const int DamageBonusPerLevel;
    const float ColdownMultiplierPerLevel;

    void LevelUp();
};

#endif