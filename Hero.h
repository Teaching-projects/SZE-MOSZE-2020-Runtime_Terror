#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Monster.h"

class Hero : public Monster 
{
    public:
    Hero(const std::string&, const int, const int, const float);    

    int getLevel() const;
    int getXp() const;
    int getMaxHealthPoints() const;

    void fightTilDeath(Monster&);
    static Hero parse(const std::string&);

    private:
    int xp = 0;
    int level = 1;
    int maxHealth;

    void LevelUp();
};

#endif