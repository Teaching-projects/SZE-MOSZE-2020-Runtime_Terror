#ifndef GAME_HEADER
#define GAME_HEADER

#include "Unit.h"
#include "Player.h"

class Game
{ 

public:

    Game(Unit&, Unit&);

private:   

    Unit unitA;
    Unit unitB;

    void SimulateTurn(Unit&, Unit&);
    void Combat();
};

#endif