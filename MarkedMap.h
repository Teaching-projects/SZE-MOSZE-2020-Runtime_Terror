/**
 * \class MarkedMap
 * 
 * \brief MarkedMap class can read a game map with specific positions from text file
 * 
 * \author Csillag Bence
 * 
 * Created on: 2020/11/26 18:21
*/

#include <string>
#include <fstream>
#include <vector>
#include "Map.h"
struct coordinate ///< Enum for a coordinates
{
    int x;
    int y;
    coordinate(int _x, int _y)
    {
        this->x = _x;
        this->y = _y;
    }
};

class MarkedMap : public Map ///< Inheritance from Map class
{
public:                               ///< Constructor of MarkedMap class
    MarkedMap(std::string &filename); ///< Constructor of MarkedMap class, which read map from file

    coordinate getHeroPosition() const;                        ///< Return with hero position
    std::vector<coordinate> getMonstarPositions(char c) const; ///< Retrun with monster positions
};