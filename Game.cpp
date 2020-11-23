#include "Game.h"
#include "Monster.h"
#include "Hero.h"

#include "string"
#include <vector>
#include <iostream>
#include <algorithm>

Game::Game(std::string mapfilename)
{
    Map map = Map(mapfilename);
    setMap(map);
}

void Game::setMap(Map &map)
{
    this->map = map;
}

void Game::putHero(Hero& hero, int x, int y)
{
    if(map.get(x, y) == map.type::Wall)
    {
        // TODO: throw exception
    }
    else if(map.get(x, y) == map.type::Free)
    { 
        this->hero = &hero;
        heroX = x;
        heroY = y;      
    }
}

void Game::putMonster(Monster monster, int x, int y)
{ 
    if(map.get(x, y) == map.type::Wall)
    {
        // TODO: throw exception
    }
    else if(map.get(x, y) == map.type::Free)
    {
        monsterPlaces.push_back(MonsterPlace(x, y, monster));
    }
}

void Game::run()
{
    std::string direction;
    int remainingMonsters  = monsterPlaces.size();

    while(hero->isAlive() && remainingMonsters > 0)
    {
        print();
        std::cout << "Direction: ";
        std::cin >> direction; 

        if(direction == "north") 
        {
            if(map.get(heroX, heroY - 1) != map.type::Wall) 
            {
                heroY -= 1;
            }
        } 
        else if(direction == "south")
        {
            if(map.get(heroX, heroY + 1) != map.type::Wall) 
            {
                heroY += 1;
            }
        } 
        else if(direction == "east")
        {
            if(map.get(heroX + 1, heroY) != map.type::Wall) 
            {
                heroX += 1;
            }
        } 
        else if(direction == "west")
        {
            if(map.get(heroX - 1, heroY) != map.type::Wall) 
            {
                heroX -= 1;
            }
        }
        else
        {
            std::cout << "Wrong direction!" << std::endl;
        }

        for (size_t i = 0; i < monsterPlaces.size(); i++) 
        {
            if(monsterPlaces[i].x == heroX && monsterPlaces[i].y == heroY && monsterPlaces[i].monster.isAlive())
            {
                std::cout << "ATTACK -> " << monsterPlaces[i].monster.getName() << std::endl;
                hero->fightTilDeath(monsterPlaces[i].monster);
                if(!monsterPlaces[i].monster.isAlive()) remainingMonsters--;
            }            
        }     
    }

    if(hero->isAlive()) std::cout << "The hero has won the game!" << std::endl;
    else std::cout << "The hero has lost the game!" << std::endl;

}

void Game::print()
{
    for (int y = 0; y < map.getHeight(); y++) 
    {  
        for (int x = 0; x < map.getWidth(y); x++) 
        {            
            int monsterCount = 0;

            for (size_t i = 0; i < monsterPlaces.size(); i++) 
            {
                if(monsterPlaces[i].x == x && monsterPlaces[i].y == y && monsterPlaces[i].monster.isAlive())
                {
                    monsterCount++;
                }
            }

            if(map.get(x, y) == map.type::Wall) std::cout << "██";
            else if (heroX == x && heroY == y) std::cout << "┣┫";
            else if (monsterCount == 1) std::cout << "M░";
            else if (monsterCount > 1) std::cout << "MM";
            else std::cout << "░░";
        }
        std::cout << std::endl;
    }
}