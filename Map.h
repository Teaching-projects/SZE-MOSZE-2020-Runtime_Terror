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

class Map
{
protected:
    std::vector<std::string> map; ///< This vector store a map

public:
    Map();                      ///< Constructor of Map class
    Map(std::string &filename); ///< Constructor of Map class, which read map from file
    enum type                   ///< Enum for 2 types of map element
    {
        Wall,
        Free
    };
    Map::type get(size_t x, size_t y) const; ///< Get a map field type

    int getWidth(int line) const; ///< This getter function return with width of map
    int getHeight() const;        ///< This getter function return with height of map

    class WrongIndexException : public std::runtime_error ///< Map class Exception function
    {
    public:
        explicit WrongIndexException(const std::string &Error) : std::runtime_error(Error) {}
    };
};