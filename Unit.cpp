#include "Unit.h"
#include <string>

bool Unit::IsDead() {
    return (health <= 0) ? true : false;
}

Unit::Unit(std::string name, int health, int damage) {
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Unit::Attack(Unit &target) {
    target.health -= this->damage;
    if (target.health < 0) target.health = 0;
}