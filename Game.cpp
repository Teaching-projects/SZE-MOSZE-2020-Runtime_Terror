#include <iostream>

#include "Game.h"

Game::Game(Player& playerA, Player& playerB) : playerA(playerA), playerB(playerB)
{
    Combat();
}

void Game::SimulateTurn(Player &attacker, Player &target)
{
    if(attacker.GetCurrentCooldown() <= target.GetCurrentCooldown()) attacker.Attack(target);
}

void Game::Combat()
{
    bool endCombat = false;
    while (!endCombat)
    {
        SimulateTurn(playerA, playerB);
        if (playerB.IsDead())
        {
            endCombat = true;
            std::cout << playerB.GetName() << " died. " << playerA.GetName() << " wins." << std::endl;
            std::cout << playerA.GetName() << ": HP: " << playerA.GetHealth() << " DMG: " << playerA.GetDamage() << " XP: " << playerA.GetXp() << " LVL: " << playerA.GetLevel() << std::endl;
        }
        else
        {
            SimulateTurn(playerB, playerA);
            if (playerA.IsDead())
            {
                endCombat = true;
                std::cout << playerA.GetName() << " died. " << playerB.GetName() << " wins." << std::endl;
                std::cout << playerB.GetName() << ": HP: " << playerB.GetHealth() << " DMG: " << playerB.GetDamage() << " XP: " << playerB.GetXp() << " LVL: " << playerB.GetLevel() << std::endl;
            }
        }
    }
}