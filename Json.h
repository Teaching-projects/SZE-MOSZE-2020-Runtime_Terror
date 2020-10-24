#include <map>
#include <string>

class Json
{
private:
    static void Validator(const std::string &text);
    static std::string Trim(const std::string &text);

public:
    static std::map<std::string, std::string> ParseString(const std::string &input);
    static std::map<std::string, std::string> ParseStream(std::istream &stream);
    static std::map<std::string, std::string> ParseFile(const std::string &filename);
};