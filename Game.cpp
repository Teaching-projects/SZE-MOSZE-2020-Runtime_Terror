#include <iostream>

#include "Game.h"

Game::Game()
{
    
}

void Game::SimulateTurn(const Unit &attacker, Unit &target) const
{
    attacker.Attack(target);
}

void Game::SimulateTurn(Player &attacker, Player &target)
{
    attacker.Attack(target);
}

void Game::Combat(Unit &a, Unit &b)
{
    bool endCombat = false;
    while (!endCombat)
    {
        SimulateTurn(a, b);
        if (b.IsDead())
        {
            endCombat = true;
            std::cout << b.GetName() << " died. " << a.GetName() << " wins." << std::endl;
            break;
        }
        SimulateTurn(b, a);
        if (a.IsDead())
        {
            endCombat = true;
            std::cout << a.GetName() << " died. " << b.GetName() << " wins." << std::endl;
            break;
        }
    }
}

void Game::Combat(Player &a, Player &b)
{
    bool endCombat = false;
    while (!endCombat)
    {
        SimulateTurn(a, b);
        if (b.IsDead())
        {
            endCombat = true;
            std::cout << b.GetName() << " died. " << a.GetName() << " wins." << std::endl;
            std::cout << a.GetName() << " - " << "HP: " << a.GetHealth() << " DMG: " << b.GetDamage() << " XP: " << a.GetXp() << " LVL: " << a.GetLevel() << std::endl;
            break;
        }
        SimulateTurn(b, a);
        if (a.IsDead())
        {
            endCombat = true;
            std::cout << a.GetName() << " died. " << b.GetName() << " wins." << std::endl;
            std::cout << b.GetName() << ": " << "HP: " << b.GetHealth() << " DMG: " << b.GetDamage() << " XP: " << b.GetXp() << " LVL: " << b.GetLevel() << std::endl;           
            break;
        }
    }
}