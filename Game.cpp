#include "Game.h"
#include "Monster.h"
#include "Hero.h"

#include "string"
#include <vector>
#include <iostream>
#include <algorithm>

Game::Game(std::string mapfilename) : hero(NULL), heroX(-1), heroY(-1)
{
    Map map = Map(mapfilename);
    setMap(map);
}

void Game::setMap(Map &map)
{
    if(getLivingMonsterCount() > 0 || hero != NULL)
    {
        throw AlreadyHasUnitsException("You can't set the map, because there are living units on it.");
    }
    else
    {
        this->map = map;
    }
}

void Game::putHero(Hero& hero, int x, int y)
{
    if(!isMapSet())
    {
        throw Map::WrongIndexException("The map isn't set.");
    }
    else if(this->hero != NULL)
    {
        throw AlreadyHasHeroException("You have already set a hero.");
    }
    else if(map.get(x, y) == map.type::Wall)
    {
        throw OccupiedException("You can't place the hero on the wall.");
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
    if(!isMapSet())
    {
        throw Map::WrongIndexException("The map isn't set.");
    }     
    else if(map.get(x, y) == map.type::Wall)
    {
        throw OccupiedException("You can't place a monster on the wall.");
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

        for (size_t i = 0; i < monsterPlaces.size(); i++) 
        {
            if(monsterPlaces[i].x == heroX && monsterPlaces[i].y == heroY && monsterPlaces[i].monster.isAlive())
            {
                fight(monsterPlaces[i].monster);
                if(!monsterPlaces[i].monster.isAlive())
                {
                    remainingMonsters--;
                }
            }            
        }

        if(remainingMonsters > 0)
        {
            std::cout << "Direction: ";
            std::cin >> direction; 
            move(direction);  
            std::cout << std::endl;
        }
    }

    if(hero->isAlive()) 
    {
        std::cout << "The hero won." << std::endl;
    }
    else 
    {
        std::cout << "The hero died." << std::endl;
    }
    hero = NULL;
}

void Game::move(std::string &direction)
{
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
}

void Game::fight(Monster &enemy)
{
    std::cout << "ATTACK -> " << enemy.getName() << std::endl;
    hero->fightTilDeath(enemy);
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

bool Game::isMapSet()
{
    return map.getHeight();
}

int Game::getLivingMonsterCount()
{
    int monsterCount = 0;
    for (size_t i = 0; i < monsterPlaces.size(); i++) 
    {
        if(monsterPlaces[i].monster.isAlive())
        {
            monsterCount++;
        }
    }
    return monsterCount;
}