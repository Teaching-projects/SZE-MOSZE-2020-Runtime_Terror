/**
 * \class JSON
 * 
 * \brief JSON Parser class containing static functions
 * The class is able to parse datas from different sources: from files, streams and strings.
 * It contains three static parse functions, and a Validator function to check wether a Json is valid or not.
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/11/14 11:14
*/

#ifndef JSON_HEADER
#define JSON_HEADER

#include <map>
#include <string>
#include <variant>
#include <iostream>
#include <list>

class JSON
{
private:
    /**
     * \brief Checks whether a string is a valid json or not
    */
    static void Validator(const std::string & /** [in] The text to be validated*/);

    /**
     * \brief Checks whether the given string is a valid number
     * \return A bool: true = the string is a valid number, false = the string is not a valid number
    */
    static bool isNumber(const std::string & /** [in] The string to be checked*/);

public:

    typedef std::list<std::variant<std::string, int, double>> list; ///< Type definition for the lists

    JSON(std::map<std::string, std::variant<std::string, int, double, list>>);

    std::map<std::string, std::variant<std::string, int, double, list>> data; ///< The parsed data in a map   

    /**
     * \brief It tells wether a key is in the map or not
     * \return A bool: true = the key exsists, false = the key does not exsist
    */
    int count(const std::string & /** [in] The given key*/);

    /**
     * \brief Parses data from string
     * \return A map of the data: key and value pairs
    */
    static JSON parseFromString(const std::string & /** [in] The string to be parsed*/);

    /**
     * \brief Parses data from stream
     * \return A map of the data: key and value pairs
    */
    static JSON parseFromStream(std::istream & /** [in] The stream to be parsed*/);

    /**
     * \brief Parses data from file
     * \return A map of the data: key and value pairs
    */
    static JSON parseFromFile(const std::string & /** [in] The name of the file to be parsed*/);

    /**
     * \brief A static function to parse the values and make a list
     * \return A list of values
    */
    static JSON::list parseList(std::string&);

    /**
     * \brief A get function to get data from the map
     * \return A type T data
    */    
    template <typename T>
    T get(const std::string &key)
    {
        return std::get<T>(data[key]);
    }

    class ParseException : virtual public std::runtime_error
    {
    public:
        explicit ParseException(const std::string &description) : std::runtime_error("Parsing error: " + description) {}
    };
};

#endif