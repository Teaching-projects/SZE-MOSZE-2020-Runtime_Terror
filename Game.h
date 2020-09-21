#ifndef GAME_HEADER
#define GAME_HEADER

#include "Unit.h"

class Game
{
public:
    Game(const Unit&, const Unit&);

private:
    Unit player;
    Unit enemy;
    void SimulateTurn(const Unit&, Unit&) const;
    void Combat();
    void PrintCurrentState() const;
};

#endif