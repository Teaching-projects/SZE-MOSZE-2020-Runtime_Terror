#include "MarkedMap.h"
#include <iostream>

MarkedMap::MarkedMap(std::string &filename) : Map(filename)
{
}

coordinate MarkedMap::getHeroPosition() const
{
    for (int i = 0; i < getHeight(); i++)
    {
        for (int j = 0; j < getWidth(i); j++)
        {
            if (map[i][j] == 'H')
            {
                coordinate c(j, i);
                return c;
            }
        }
    }
    throw Herodoesntexist("Hero doesn't exist");
}
std::vector<coordinate> MarkedMap::getMonsterPositions(char c) const
{
    std::vector<coordinate> coord;
    for (int i = 0; i < getHeight(); i++)
    {
        for (int j = 0; j < getWidth(i); j++)
        {
            if (map[i][j] == c)
            {
                coordinate temp(j, i);
                coord.push_back(temp);
            }
        }
    }
    return coord;
}