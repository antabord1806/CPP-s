#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <exception>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdlib>

class BitcoinExchange{
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange(void);
        void processingInput(std::string input);
    private:
        std::map<std::string, double> _dataBase;
        int    dateParsing(std::string date);
        void    importingData(void);
        void    comparingData(std::map<std::string, double> database);
};

#endif