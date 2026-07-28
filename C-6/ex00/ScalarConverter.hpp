#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <sstream>
#include <iomanip>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &copy);
        ~ScalarConverter();
        ScalarConverter &operator=(ScalarConverter const &copy);

        static bool     IsChar(const std::string &value);
        static bool     IsInt(const std::string &value);
        static bool     IsFloat(const std::string &value);
        static bool     IsDouble(const std::string &value);
        static bool     IsPseudo(const std::string &value);
    public:
        static void     convert(const std::string &literal);
};


#endif