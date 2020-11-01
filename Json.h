/**
 * \class Json
 * 
 * \brief Json Parser class containing static functions
 * The class is able to parse datas from different sources: from files, streams and srings.
 * It contains three static parse functions, and a Trim and Validator function to check wether a Json is valid or not.
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/10/29 10:56
*/

#include <map>
#include <string>

class Json
{
private:

    /**
     * \brief Checks whether a string is a valid json or not
    */
    static void Validator(const std::string &text /** [in] The text to be validated*/);
    
    /**
     * \brief Removes unnecessary space characters from a string
     * \return A string without spaces
    */
    static std::string Trim(const std::string &text /** [in] The text to be trimmed*/);

public:

    /**
     * \brief Parses data from string
     * \return A map of the data: key and value pairs
    */
    static std::map<std::string, std::string> ParseString(const std::string &input /** [in] The string to be parsed*/);

    /**
     * \brief Parses data from stream
     * \return A map of the data: key and value pairs
    */
    static std::map<std::string, std::string> ParseStream(std::istream &stream /** [in] The stream to be parsed*/);

    /**
     * \brief Parses data from file
     * \return A map of the data: key and value pairs
    */
    static std::map<std::string, std::string> ParseFile(const std::string &filename /** [in] The name of the file to be parsed*/);
};