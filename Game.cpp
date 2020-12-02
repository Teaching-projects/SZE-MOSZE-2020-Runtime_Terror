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

    attackMonsters(remainingMonsters);

    while(hero->isAlive() && remainingMonsters > 0)
    {     
        print();

        if(remainingMonsters > 0)
        {
            do
            {
                std::cout << "Direction: ";
                std::cin >> direction; 
            }
            while(!isValidDirection(direction));
            move(direction);
            std::cout << std::endl;
        }
        attackMonsters(remainingMonsters);
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
}

bool Game::isValidDirection(std::string &direction)
{
    if(direction == "north" || direction == "south" || direction == "west" || direction == "east") return true;
    else return false;
}

void Game::attackMonsters(int &remainingMonsters)
{
    for (size_t i = 0; i < monsterPlaces.size(); i++) 
    {
        if(monsterPlaces[i].x == heroX && monsterPlaces[i].y == heroY && monsterPlaces[i].monster.isAlive())
        {
            std::cout << "ATTACK -> " << monsterPlaces[i].monster.getName() << std::endl;
            hero->fightTilDeath(monsterPlaces[i].monster);

            if(!monsterPlaces[i].monster.isAlive())
            {
                remainingMonsters--;
            }
        }            
    }    
}

void Game::print()
{
    const int startY = heroY - hero->getLightRadius() > 0 ? heroY - hero->getLightRadius() : 0;
    const int endY = heroY + hero->getLightRadius() + 1 < map.getHeight() ? heroY + hero->getLightRadius() + 1 : map.getHeight();

    for (int y = startY; y < endY; y++) 
    {  
        const int startX = heroX - hero->getLightRadius() > 0 ? heroX - hero->getLightRadius() : 0;
        const int endX = heroX + hero->getLightRadius() + 1 < map.getWidth(y) ? heroX + hero->getLightRadius() + 1 : map.getWidth(y);   

        for (int x = startX; x < endX; x++) 
        {    
            if(map.get(x, y) == map.type::Wall) std::cout << "██";
            else if (heroX == x && heroY == y) std::cout << "┣┫";
            else
            {
                int monsterCount = 0;

                for (size_t i = 0; i < monsterPlaces.size(); i++) 
                {
                    if(monsterPlaces[i].x == x && monsterPlaces[i].y == y && monsterPlaces[i].monster.isAlive())
                    {
                        monsterCount++;
                    }
                }

                if (monsterCount == 1) std::cout << "M░";
                else if (monsterCount > 1) std::cout << "MM";
                else std::cout << "░░";
            }                                         
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