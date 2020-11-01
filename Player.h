/**
 * \class Player
 * 
 * \brief Player class inherited from Unit class
 * The Player is a Unit, but it has experience points and level value.
 * In case of a level up, the damage, health and max health values are changing.
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/10/29 10:11
*/

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Unit.h"

class Player : public Unit 
{
    public:
    Player(const std::string&, const int, const int, const float); ///< Constructor of Player class    

    int GetLevel() const; ///< This is a simple getter function for level value
    int GetXp() const; ///< This is a simple getter function for xp value

    /**
     * \brief Damages target Player using the Unit's Attack function, increasing the xp and calling the LevelUp() function in case of level up
    */
    void Attack(Player& /** [in] The Player the attack is targeting*/);
    
    /**
     * \brief Fills Player data from JSON
     * \return Player with values from the specified JSON
    */
    static Player parsePlayer(const std::string& /** [in] The name of the file to be parsed*/);

    private:
    int xp = 0; ///< The experience points of a Player
    int level = 1; ///< The level of a Player
    int maxHealth; ///< The maximum health value of a Player

    /**
     * \brief Increasing the Player's level, maxHealth and damage; and setting the health value to maxHealth
    */
    void LevelUp();
};

#endif