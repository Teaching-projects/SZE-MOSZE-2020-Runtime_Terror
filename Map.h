#include <string>
#include <fstream>
#include <vector>

class Map
{
private:
    std::vector<std::string> map;

public:
    Map();
    Map(std::string &filename);
    enum type
    {
        Wall,
        Free
    };
    Map::type get(size_t x, size_t y) const;

    int getWidth(int line) const;
    int getHeight() const;

    class WrongIndexException : public std::runtime_error
    {
    public:
        explicit WrongIndexException(const std::string &Error) : std::runtime_error(Error) {}
    };
};