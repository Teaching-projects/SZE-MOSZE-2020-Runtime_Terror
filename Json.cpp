#include "Json.h"
#include <iostream>

#include <fstream>
#include <regex>

std::map<std::string, std::string> Json::ParseString(const std::string &input)
{
    std::string text = input;
    std::vector<std::string> data;
    std::map<std::string, std::string> mapedData;

    text.push_back('\"');
    std::string chars = ": {},\r";
    for (size_t i = 0; i < chars.size(); i++)
    {
        text.erase(remove(text.begin(), text.end(), chars[i]), text.end());
    }
    text = std::regex_replace(text, std::regex("\"\""), "\"");
    text.erase(text.begin());

    size_t pos = 0;
    std::string token;
    while ((pos = text.find("\"")) != std::string::npos)
    {
        token = text.substr(0, pos);
        data.push_back(token);
        text.erase(0, pos + 1);
    }
    for (size_t i = 0; i < data.size() / 2; i++)
    {
        mapedData[data[2 * i]] = data[2 * i + 1];
    }
    return mapedData;
}
std::map<std::string, std::string> Json::ParseStream(std::istream &stream)
{
    std::string text, currentLine;

    while (getline(stream, currentLine))
    {
        text.append(currentLine);
    }
    return ParseString(text);
}
std::map<std::string, std::string> Json::ParseFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("file " + filename + " doesn't exist");

    std::map<std::string, std::string> data = ParseStream(file);

    file.close();
    return data;
}