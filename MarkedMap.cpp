#include "MarkedMap.h"
#include <iostream>

MarkedMap::MarkedMap(std::string &filename) : Map(filename)
{
}

coordinate MarkedMap::getHeroPosition() const
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] == 'H')
            {
                coordinate c(i, j);
                return c;
            }
        }
    }
}
std::vector<coordinate> MarkedMap::getMonstarPositions(char c) const
{
    std::vector<coordinate> coord;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] == c)
            {
                coordinate temp(i, j);
                coord.push_back(temp);
            }
        }
    }
    return coord;
}