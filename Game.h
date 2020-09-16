#ifndef GAME_HEADER
#define GAME_HEADER

#include "Unit.h"

class Game {
    public:
    Unit player;
    Unit enemy;
    Game(Unit, Unit);
    const void SimulateTurn(Unit&, Unit&);
    const void Combat();
    const void PrintCurrentState();
};

#endif