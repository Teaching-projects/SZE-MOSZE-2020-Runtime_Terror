#include <iostream>

#include "Game.h"

Game::Game(const Unit player, const Unit enemy) : player(player), enemy(enemy)
{
    Combat(); //ha kivesszük a privátból akkor mehet vissza a mainbe
}

void Game::SimulateTurn(const Unit &attacker, Unit &target) const
{
    std::cout << attacker.name << " -> " << target.name << std::endl;
    attacker.Attack(target);
    PrintCurrentState();
}

void Game::Combat()
{
    PrintCurrentState();
    bool endCombat = false;
    while (!endCombat)
    {
        SimulateTurn(player, enemy);
        if (enemy.IsDead())
        {
            endCombat = true;
            std::cout << enemy.name << " died. " << player.name << " wins." << std::endl;
            break;
        }
        SimulateTurn(enemy, player);
        if (player.IsDead())
        {
            endCombat = true;
            std::cout << player.name << " died. " << enemy.name << " wins." << std::endl;
            break;
        }
    }
}

void Game::PrintCurrentState() const
{
    std::cout << player.name << ": "
              << "HP: " << player.health << ", DMG: " << player.damage << std::endl;
    std::cout << enemy.name << ": "
              << "HP: " << enemy.health << ", DMG: " << enemy.damage << std::endl;
}