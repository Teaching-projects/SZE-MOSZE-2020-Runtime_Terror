#include <map>
#include <string>

class Json
{
public:
    static std::map<std::string, std::string> ParseString(const std::string &input);
    static std::map<std::string, std::string> ParseStream(std::istream &stream);
};