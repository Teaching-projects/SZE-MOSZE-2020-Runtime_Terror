#ifndef GAME_HEADER
#define GAME_HEADER

#include "Unit.h"
#include "Player.h"

class Game
{
public:
    void Combat(Unit&, Unit&);
    void Combat(Player&, Player&);

private:    
    void SimulateTurn(const Unit&, Unit&) const;
    void SimulateTurn(Player&, Player&);
};

#endif