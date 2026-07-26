#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <exception>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <vector>

class BitcoinExchange{
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange(void);
        void processingInput(std::string input);
    private:
        std::vector<std::pair<std::string, double> > _input;
        int    dateParsing(std::string date);
        void    importingData(void);
        void    comparingData(const std::map<std::string, double> &database);
};

#endif