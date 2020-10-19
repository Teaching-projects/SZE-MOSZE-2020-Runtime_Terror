#include <map>
#include <string>

class Json
{
public:
    static void Validator(std::string text);
    static std::string Trim(const std::string &text);
    static std::map<std::string, std::string> ParseString(const std::string &input);
    static std::map<std::string, std::string> ParseStream(std::istream &stream);
    static std::map<std::string, std::string> ParseFile(const std::string &filename);
};