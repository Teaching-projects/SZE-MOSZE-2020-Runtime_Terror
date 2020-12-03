#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(){};

Map::Map(std::string &filename)
{
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("doesn't exist file");

    std::string line;
    while (getline(file, line))
    {
        map.push_back(line);
    }
    file.close();
}

Map::type Map::get(size_t x, size_t y) const
{
    if (y >= map.size())
        throw WrongIndexException("y coordinate is out of range");
    if (x >= map[y].length())
        throw WrongIndexException("x coordinate is out of range");

    return map[y][x] == '#' ? Map::type::Wall : Map::type::Free;
}

int Map::getHeight() const
{
    return map.size();
}

int Map::getWidth(int line) const
{
    return map[line].length();
}

int Map::getMaxWidth() const 
{
    size_t maxWidth = 0;
    for(size_t i = 0; i < map.size(); i++)
    {
        if(map[i].length() > maxWidth) maxWidth = map[i].length(); 
    }
    return maxWidth;
}