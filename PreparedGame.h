/**
 * \class PreparedGame
 * 
 * \brief PreparedGame class inherited from Game class
 * The class runs the game and places units on the map according to a json file.
 * 
 * \author Jaksics Benedek
 * 
 * Created on: 2020/12/13 18:25
*/

#include <string>

#include "Game.h"
#include "Renderer.h"

#ifndef PREPAREDGAME_HEADER
#define PREPAREDGAME_HEADER

class PreparedGame : Game {

    public:
        PreparedGame(std::string mapjson); ///< Constructor of PreparedGame class, reads map, monsters and hero from file 
        void run(); ///< The function that runs the game
        void registerRenderer(Renderer*); ///< Registers a renderer
};

#endif