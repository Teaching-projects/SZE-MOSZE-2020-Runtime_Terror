#include "Unit.h"
#include <string>

bool Unit::IsDead() {
    return (health <= 0) ? true : false;
}

Unit::Unit(std::string name, int health, int damage) : name(name), health(health), damage(damage) {
}

const void Unit::Attack(Unit &target) {
    target.health -= damage;
    if (target.health < 0) target.health = 0;
}