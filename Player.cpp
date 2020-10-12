#include "Player.h"

Player::Player(const std::string& name, const int health, const int damage) : Unit{name, health, damage}
{
     maxHealth = health;
}

int Player::GetLevel() const 
{
    return level;
}

int Player::GetXp() const 
{
    return xp;
}

void Player::LevelUp() 
{
    level += 1;
    damage += damage * 0.1;
    maxHealth += maxHealth * 0.1;
    health = maxHealth;
}

void Player::Attack(Player& target) 
{
    Unit::Attack(target);
    xp += damage;
    while(level - 1 != (xp / 100))
    {
        LevelUp();
    }
}

Player Player::parsePlayer(const std::string& fileName)
{
    Unit parsedUnit = Unit::parseUnit(fileName);
    return Player(parsedUnit.GetName(), parsedUnit.GetHealth(), parsedUnit.GetDamage());
}