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

void Game::putHero(Hero hero, int x, int y)
{
    if(map.get(x, y) == map.type::Wall)
    {
        // TODO: throw exception
    }
    else if(map.get(x, y) == map.type::Free)
    {
        heroPlaces.push_back(HeroPlace(x, y, hero));           
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

    while(heroPlaces[0].hero.isAlive() && remainingMonsters > 0)
    {
        print();
        std::cout << "Direction: ";
        std::cin >> direction; 

        if(direction == "north") 
        {
            if(map.get(heroPlaces[0].x, heroPlaces[0].y - 1) != map.type::Wall) 
            {
                heroPlaces[0].y -= 1;
            }
        } 
        else if(direction == "south")
        {
            if(map.get(heroPlaces[0].x, heroPlaces[0].y + 1) != map.type::Wall) 
            {
                heroPlaces[0].y += 1;
            }
        } 
        else if(direction == "east")
        {
            if(map.get(heroPlaces[0].x + 1, heroPlaces[0].y) != map.type::Wall) 
            {
                heroPlaces[0].x += 1;
            }
        } 
        else if(direction == "west")
        {
            if(map.get(heroPlaces[0].x - 1, heroPlaces[0].y) != map.type::Wall) 
            {
                heroPlaces[0].x -= 1;
            }
        }
        else
        {
            std::cout << "Wrong direction!" << std::endl;
        }

        for (size_t i = 0; i < monsterPlaces.size(); i++) 
        {
            if(monsterPlaces[i].x == heroPlaces[0].x && monsterPlaces[i].y == heroPlaces[0].y && monsterPlaces[i].monster.isAlive())
            {
                std::cout << "ATTACK -> " << monsterPlaces[i].monster.getName() << std::endl;
                heroPlaces[0].hero.fightTilDeath(monsterPlaces[i].monster);
                if(!monsterPlaces[i].monster.isAlive()) remainingMonsters--;
            }            
        }     
    }

    if(heroPlaces[0].hero.isAlive()) std::cout << "The hero has won the game!" << std::endl;
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
            else if (heroPlaces[0].x == x && heroPlaces[0].y == y) std::cout << "┣┫";
            else if (monsterCount == 1) std::cout << "M░";
            else if (monsterCount > 1) std::cout << "MM";
            else std::cout << "░░";
        }
        std::cout << std::endl;
    }
}