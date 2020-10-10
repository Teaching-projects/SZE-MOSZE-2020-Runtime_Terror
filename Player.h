#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Unit.h"

class Player : public Unit 
{
    public:
    Player(const std::string, const int, const int);    

    int GetLevel() const;
    int GetXp() const;

    private:
    int xp = 0;
    int level = 1;
    int maxHealth;

    void LevelUp();
};

#endif