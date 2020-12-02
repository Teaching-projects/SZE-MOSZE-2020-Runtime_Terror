#include "MarkedMap.h"
#include <iostream>

MarkedMap::MarkedMap(std::string &filename) : Map(filename)
{
}

coordinate MarkedMap::getHeroPosition() const
{
    for (int i = 0; i < getHeight(); i++)
    {
        for (int j = 0; j < getWidth(j); j++)
        {
            if (map[i][j] == 'H')
            {
                coordinate c(i, j);
                return c;
            }
        }
    }
    throw Herodoenstexist("Hero doesn't exist");
}
std::vector<coordinate> MarkedMap::getMonstarPositions(char c) const
{
    std::vector<coordinate> coord;
    for (int i = 0; i < getHeight(); i++)
    {
        for (int j = 0; j < getWidth(j); j++)
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