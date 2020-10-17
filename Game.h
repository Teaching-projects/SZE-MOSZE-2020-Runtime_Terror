#ifndef GAME_HEADER
#define GAME_HEADER

#include "Unit.h"
#include "Player.h"

class Game
{ 

public:

    Game(Player&, Player&);

private:   

    Player playerA;
    Player playerB;

    void SimulateTurn(Player&, Player&);
    void Combat();
};

#endif