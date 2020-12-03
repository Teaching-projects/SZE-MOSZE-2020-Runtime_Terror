#include <string>

#include "Game.h"

#ifndef PREPAREDGAME_HEADER
#define PREPAREDGAME_HEADER

class PreparedGame : Game {

    public:
        PreparedGame(std::string mapjson);
        void run();

};

#endif