#include "Json.h"
#include <iostream>

#include <fstream>
#include <regex>

JSON::JSON(std::map<std::string, std::any> data) : data(data)
{
}

void JSON::Validator(const std::string &text)
{
    int quote = 0;
    int j = 0;
    int first = text.find('{');
    int last = text.find('}'); //utolső hasznos karakter
    if (first == -1)
        throw std::runtime_error("Invalid Json");
    std::string trimmedtext = text.substr(first, last - first + 1);
    int dpont = std::count(trimmedtext.begin(), trimmedtext.end(), ':');
    int datanumber = std::count(trimmedtext.begin(), trimmedtext.end(), ',');

    if ((trimmedtext.find('{') != std::string::npos && trimmedtext.find('}') != std::string::npos) && (dpont == (datanumber + 1)))
    {
        trimmedtext.erase(trimmedtext.end() - 1);
        trimmedtext.append(",}");
        for (int i = 0; i < dpont; i++)
        {
            do
            {
                if (trimmedtext[j] == '\"')
                    quote++;
                j++;
            } while (trimmedtext[j] != ':');
            if (trimmedtext[j] == ':' && quote != 2)
            {

                throw std::runtime_error("Invalid Json");
            }

            quote = 0;

            do
            {
                if (trimmedtext[j] == '\"')
                    quote++;
                j++;
            } while (trimmedtext[j] != ',');
            if (!(trimmedtext[j] == ',' && (quote == 0 || quote == 2)))
            {

                throw std::runtime_error("Invalid Json");
            }

            quote = 0;
        }
    }
    else
    {
        throw std::runtime_error("Invalid Json");
    }
}

std::string JSON::Trim(const std::string &text)
{
    auto start = text.begin();
    while (start != text.end() && std::isspace(*start))
    {
        start++;
    }

    auto end = text.end();
    do
    {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

int JSON::count(const std::string &key)
{
    return data.count(key);
}

JSON JSON::parseFromString(const std::string &input)
{
    std::string text = input;
    std::vector<std::string> data;
    std::map<std::string, std::any> mapedData;

    Validator(input);

    text.push_back('\"');
    std::string chars = " :{},\r";
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
        token = Trim(token);
        data.push_back(token);
        text.erase(0, pos + 1);
    }
    for (size_t i = 0; i < data.size() / 2; i++)
    {
        mapedData[data[2 * i]] = data[2 * i + 1];       
    }
    return JSON(mapedData);
}

JSON JSON::parseFromStream(std::istream &stream)
{
    std::string text, currentLine;

    while (getline(stream, currentLine))
    {
        text.append(currentLine);
    }
    return parseFromString(text);
}

JSON JSON::parseFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("file " + filename + " doesn't exist");

    return  parseFromStream(file);
}