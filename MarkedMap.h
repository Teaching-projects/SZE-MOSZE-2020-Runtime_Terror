/**
 * \class Map
 * 
 * \brief Map class can read a game map from text file
 * 
 * \author Csillag Bence
 * 
 * Created on: 2020/11/26 18:21
*/

#include <string>
#include <fstream>
#include <vector>
#include "Map.h"
struct coordinate ///< Enum for 2 types of map element
{
    int x;
    int y;
    coordinate(int _x, int _y)
    {
        this->x = _x;
        this->y = _y;
    }
};

class MarkedMap : public Map
{
public:                               ///< Constructor of Map class
    MarkedMap(std::string &filename); ///< Constructor of Map class, which read map from file

    coordinate getHeroPosition() const;                        ///< Get a map field type
    std::vector<coordinate> getMonstarPositions(char c) const; ///< Get a map field type
};