#ifndef GAME_HEADER
#define GAME_HEADER

#include "Unit.h"

class Game {
    public:
    Unit player;
    Unit enemy;
    Game(Unit&, Unit&);
    void SimulateTurn(Unit&, Unit&);
    void Combat();
    void PrintCurrentState();
};

#endif