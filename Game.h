/**
 * \class Game
 * 
 * \brief Game class
 * 
 * \author Jaksics Benedek
 * 
 * Created on: 2020/10/12 13:01
*/

#ifndef GAME_HEADER
#define GAME_HEADER

#include "Unit.h"

class Game
{
public:
    /**
     * \brief Constructor of the Game class
     * \param Unit First participant of a game loop, the player character.
     * \param Unit Second participant of a game loop, the enemy character.
    */
    Game(const Unit&, const Unit&);

private:
    Unit player; ///< The player/initiator character
    Unit enemy; ///< The enemy/receiver character
    
    /**
     * \brief Runs one attack between two units using the Attack() function, if the attacker's cooldown is low enough
     * \param Unit The attacker unit
     * \param Unit The unit being attacked
    */
    void SimulateTurn(Unit&, Unit&) const;

    void Combat(); ///< Simulates turns of attacks using SimulateTurn, until one of the units dies, then prints the winner's name to the console 
};

#endif