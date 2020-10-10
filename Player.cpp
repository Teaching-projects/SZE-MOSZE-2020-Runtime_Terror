#include "Player.h"

Player::Player(const std::string name, const int health, const int damage) 
    : Unit{name, health, damage}
{
     maxHealth = health;
}

