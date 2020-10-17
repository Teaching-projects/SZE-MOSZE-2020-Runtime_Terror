#include <iostream>

#include "Game.h"

Game::Game(Unit& unitA, Unit& unitB) : unitA(unitA), unitB(unitB)
{
    Combat();
}

void Game::SimulateTurn(Unit &attacker, Unit &target)
{
    attacker.Attack(target);
}

void Game::Combat()
{
    bool endCombat = false;
    while (!endCombat)
    {
        SimulateTurn(unitA, unitB);
        if (unitB.IsDead())
        {
            endCombat = true;
            std::cout << unitB.GetName() << " died. " << unitA.GetName() << " wins." << std::endl;
        }
        else
        {
            SimulateTurn(unitB, unitA);
            if (unitA.IsDead())
            {
                endCombat = true;
                std::cout << unitA.GetName() << " died. " << unitB.GetName() << " wins." << std::endl;           
            }
        }
    }
}