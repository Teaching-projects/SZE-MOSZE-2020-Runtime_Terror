#ifndef GAME_HEADER
#define GAME_HEADER

#include "Unit.h"
#include "Player.h"

class Game
{
public:
    Game();
    void Combat(Unit&, Unit&);
    void Combat(Player&, Player&);

private:    
    void SimulateTurn(const Unit&, Unit&) const;
    void SimulateTurn(const Player&, Player&);
};

#endif