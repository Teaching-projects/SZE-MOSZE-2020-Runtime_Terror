#ifndef GAME_HEADER
#define GAME_HEADER

#include "Map.h"
#include "Monster.h"
#include "Hero.h"

#include "string"
#include <list>
#include <variant>
#include <iostream>

class Game 
{
    public:

    Game();
    Game(std::string);  

    void putHero(Hero, int, int);
    void putMonster(Monster, int, int);  

    void run();
    void print();

    private:   

    struct HeroPlace
    {
        int x;
        int y;
        Hero hero;

        HeroPlace(int x, int y, Hero& hero) : x(x), y(y), hero(hero) {}
    };

    struct MonsterPlace
    {
        int x;
        int y;
        Monster monster;

        MonsterPlace(int x, int y, Monster& monster) : x(x), y(y), monster(monster) {}
    };

    Map map;
    std::vector<HeroPlace> heroPlaces;
    std::vector<MonsterPlace> monsterPlaces;

    void setMap(Map&);

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