#include "Map.h"
#include <fstream>
#include <iostream>

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
    if (y >= map.size() || y < 0)
        throw WrongIndexException("y coordinate is out of range");
    if (x >= map[y].length() || x < 0)
        throw WrongIndexException("x coordinate is out of range");

    return map[y][x] == '#' ? Map::type::Wall : Map::type::Free; // wall = 0 free = 1
}