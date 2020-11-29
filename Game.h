/**
 * \class Game
 * 
 * \brief Game class runs the game, and it can add units to the game
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/11/27 10:21
*/

#ifndef GAME_HEADER
#define GAME_HEADER

#include "Map.h"
#include "Monster.h"
#include "Hero.h"

#include "string"
#include <variant>
#include <iostream>

class Game 
{
    public:

    Game(); ///< Constructor of Game class
    Game(std::string); ///< Constructor of Game class, which reads map from file

    void setMap(Map&); ///< Function to set the map
    void putHero(Hero&, int, int); ///< Function to add a Hero to the game
    void putMonster(Monster, int, int);  ///< Function to add a Monster to the game

    void run(); ///< The function that runs the game

    private:   

    /**
     * \brief A struct to store a place where a Monster is located
    */
    struct MonsterPlace
    {
        int x; ///< Location of the Monster
        int y; ///< Location of the Monster
        Monster monster; ///< A Monster in the game

        MonsterPlace(int x, int y, Monster monster) : x(x), y(y), monster(monster) {}
    };

    Map map; ///< It stores the map: walls and empty fields
    std::vector<MonsterPlace> monsterPlaces; ///< A vector which contains the location of the Monsters

    Hero* hero; ///< A pointer to the Hero
    int heroX, heroY; ///< The location of the Hero
 
    void move(std::string&); ///< It moves the Hero, paramter: direction string
    void attackMonsters(int&); ///< Function to attack Monsters
    void print(); ///< Function to print the current state of the game
    bool isMapSet(); ///< Function to decide wether the map is set or not
    int getLivingMonsterCount(); ///< A getter function to get the number of living Monsters
    bool isValidDirection(std::string&); ///< Returns whether the given direction is valid or not

    class OccupiedException : public std::runtime_error
    {
        public:
        explicit OccupiedException(const std::string &Error) : std::runtime_error(Error) {}
    };

    class AlreadyHasHeroException : public std::runtime_error
    {
        public:
        explicit AlreadyHasHeroException(const std::string &Error) : std::runtime_error(Error) {}
    };

    class AlreadyHasUnitsException : public std::runtime_error
    {
        public:
        explicit AlreadyHasUnitsException(const std::string &Error) : std::runtime_error(Error) {}
    };   
};

#endif