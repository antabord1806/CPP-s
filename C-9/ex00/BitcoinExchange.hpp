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
        int    dateParsing(std::string date);
        void    importingData(const std::string &inputFile);
        void    comparingData(const std::map<std::string, double> &dataset, const std::string &line);
};

#endif