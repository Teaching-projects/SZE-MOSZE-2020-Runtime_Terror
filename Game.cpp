#include <iostream>

#include "Game.h"

Game::Game(Unit player, Unit enemy) : player(player), enemy(enemy) {
}

const void Game::SimulateTurn(Unit &attacker, Unit &target) {          
    std::cout << attacker.name << " -> " << target.name << std::endl;
    attacker.Attack(target);
    PrintCurrentState();             
}

const void Game::Combat() {
    PrintCurrentState();
    bool endCombat = false;
    while (!endCombat) {
        SimulateTurn(player, enemy);
        if (enemy.IsDead()) {
            endCombat = true;
            std::cout << enemy.name << " died. " << player.name << " wins." << std::endl;
            break;
        }  
        SimulateTurn(enemy, player);    
        if (player.IsDead()) {
            endCombat = true;
            std::cout << player.name << " died. " << enemy.name << " wins." << std::endl;
            break;
        }
    }
}

const void Game::PrintCurrentState() {
    std::cout << player.name << ": " << "HP: " << player.health << ", DMG: " << player.damage << std::endl;
    std::cout << enemy.name << ": " << "HP: " << enemy.health << ", DMG: " << enemy.damage << std::endl;
}