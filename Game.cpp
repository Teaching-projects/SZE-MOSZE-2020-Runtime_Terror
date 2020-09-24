#include <iostream>

#include "Game.h"

Game::Game(const Unit &player, const Unit &enemy) : player(player), enemy(enemy)
{
    Combat();
}

void Game::SimulateTurn(const Unit &attacker, Unit &target) const
{
    attacker.Attack(target);
}

void Game::Combat()
{
    bool endCombat = false;
    while (!endCombat)
    {
        SimulateTurn(player, enemy);
        if (enemy.IsDead())
        {
            endCombat = true;
            std::cout << enemy.GetName() << " died. " << player.GetName() << " wins." << std::endl;
            break;
        }
        SimulateTurn(enemy, player);
        if (player.IsDead())
        {
            endCombat = true;
            std::cout << player.GetName() << " died. " << enemy.GetName() << " wins." << std::endl;
            break;
        }
    }
}

void Game::PrintCurrentState() const
{
    std::cout << player.GetName() << ": "
              << "HP: " << player.GetHealth() << ", DMG: " << player.GetDamage() << std::endl;
    std::cout << enemy.GetName() << ": "
              << "HP: " << enemy.GetHealth() << ", DMG: " << enemy.GetDamage() << std::endl;
}