#include "Unit.h"
  
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

bool Unit::IsDead() const
{
    return health <= 0;
}

Unit::Unit(const std::string name, const int health, const int damage) : name(name), health(health), damage(damage)
{
}

std::string Unit::GetName() const 
{
    return name;
}

int Unit::GetHealth() const 
{
    return health;
}

int Unit::GetDamage() const 
{
    return damage;
}

void Unit::Attack(Unit &target) const
{
    target.SufferDamage(damage);
}

void Unit::SufferDamage(int damageRecieved)
{
    health -= damageRecieved;
    if(health < 0) {
        health = 0;
    }
}

Unit Unit::parseUnit(const std::string fileName) 
{
    std::vector<std::string> text;
    std::string currentLine;

    std::ifstream file;

    file.open(fileName);

    if(file) {
        while (getline(file, currentLine))
        {
            text.push_back(currentLine);
        }

        text.erase(text.end());
        text.erase(text.begin());

        for (size_t i = 0; i < text.size(); i++)
        {
            text[i].erase(remove(text[i].begin(), text[i].end(), ' '), text[i].end());
            text[i].erase(remove(text[i].begin(), text[i].end(), '"'), text[i].end());
            text[i].erase(remove(text[i].begin(), text[i].end(), ','), text[i].end());
            text[i].erase(remove(text[i].begin(), text[i].end(), '\r'), text[i].end());
        }

        for (size_t i = 0; i < text.size(); i++)
        {
            size_t pos = 0;
            while ((pos = text[i].find(':')) != std::string::npos)
            {
                text[i].erase(0, pos + 1);
            }
        }
    
        return Unit(text[0],std::stoi(text[1]),std::stoi(text[2]));
    
    } else {
        throw std::runtime_error("file " + fileName + " doesn't exist");
    }    

}