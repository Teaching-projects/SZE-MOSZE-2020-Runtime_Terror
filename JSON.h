/**
 * \class JSON
 * 
 * \brief JSON Parser class containing static functions
 * The class is able to parse datas from different sources: from files, streams and strings.
 * It contains three static parse functions, and a Validator function to check wether a Json is valid or not.
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/10/29 10:56
*/

#ifndef JSON_HEADER
#define JSON_HEADER

#include <map>
#include <string>
#include <any>
#include <iostream>

class JSON
{
    std::map<std::string, std::any> data;

private:

    /**
     * \brief Checks whether a string is a valid json or not
    */
    static void Validator(const std::string& /** [in] The text to be validated*/);
    static bool isNumber(const std::string&);

public:
    JSON(std::map<std::string, std::any>);
    int count(const std::string&);

    /**
     * \brief Parses data from string
     * \return A map of the data: key and value pairs
    */
    static JSON parseFromString(const std::string& /** [in] The string to be parsed*/);

    /**
     * \brief Parses data from stream
     * \return A map of the data: key and value pairs
    */
    static JSON parseFromStream(std::istream& /** [in] The stream to be parsed*/);

    /**
     * \brief Parses data from file
     * \return A map of the data: key and value pairs
    */
    static JSON parseFromFile(const std::string& /** [in] The name of the file to be parsed*/);

    template <typename T>
    T get(const std::string &key)
    {
        return std::any_cast<T>(data[key]);
    }

    class ParseException : virtual public std::runtime_error
    {
    public:
        explicit ParseException(const std::string &description) : std::runtime_error("Parsing error: " + description) {}
    };

};

#endif