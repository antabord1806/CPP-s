#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy): _input(copy._input){}

BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy){
    if (this != &copy)
        _input = copy._input;
    return *this;
}

static std::string trim(const std::string &str){
    std::string::size_type start;
    std::string::size_type end;

    start = str.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";

    end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

static bool convertDouble(const std::string &str, double &value){
    std::istringstream stream(str);
    char extra;

    if (!(stream >> value))
        return false;
    if (stream >> extra)
        return false;
    return true;
}

void BitcoinExchange::processingInput(std::string input){
    std::ifstream stream(input.c_str());
    std::string line;

    if (!stream.is_open())
        throw std::runtime_error("Error: could not open input file.");

    while (std::getline(stream, line))
    {
        std::string::size_type delPos = line.find('|');
        double value;

        if (delPos == std::string::npos){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, delPos));
        std::string valueString = trim(line.substr(delPos + 1));

        if (!convertDouble(valueString, value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        _input.push_back(std::make_pair(date, value));
    }

    importingData();
}

int BitcoinExchange::dateParsing(std::string date){
    if (date.length() != 10)
        return 0;

    if (date[4] != '-' || date[7] != '-')
        return 0;

    for (std::size_t i = 0; i < date.length(); i++){
        if (i == 4 || i == 7)
            continue;

        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return 0;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    int maxDay = 31;

    if (year < 0)
        return 0;

    if (month < 1 || month > 12)
        return 0;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDay = 30;
    else if (month == 2){
        maxDay = 28;

        if ((year % 4 == 0 && year % 100 != 0)
            || year % 400 == 0)
            maxDay = 29;
    }

    if (day < 1 || day > maxDay)
        return 0;

    return 1;
}

void BitcoinExchange::importingData(){
    std::ifstream file("data.csv");
    std::map<std::string, double> data;
    std::string line;

    if (!file.is_open())
        throw std::out_of_range("Cant read database!");

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::string::size_type delPos = line.find(',');
        double value;

        if (delPos == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, delPos));
        std::string valueString = trim(line.substr(delPos + 1));

        if (!convertDouble(valueString, value))
            continue;

        data.insert(std::make_pair(date, value));
    }

    comparingData(data);
}

void BitcoinExchange::comparingData( const std::map<std::string, double> &dataset){
    std::map<std::string, double>::const_iterator datasetIt;
    double printValue;

    for (std::vector<std::pair<std::string, double> >::size_type inputIt = 0; inputIt < _input.size(); inputIt++){
        if (!dateParsing(_input[inputIt].first)){
            std::cout << "Error: bad input => " << _input[inputIt].first << std::endl;
            continue;
        }

        if (_input[inputIt].second > 1000){
            std::cout << "Error: too large a number" << std::endl;
            continue;
        }

        if (_input[inputIt].second < 0){
            std::cout << "Error: not a positive number" << std::endl;
            continue;
        }

        if (dataset.empty()){
            std::cout << "Error: empty database" << std::endl;
            return;
        }

        datasetIt = dataset.lower_bound(_input[inputIt].first);

        if (datasetIt == dataset.end())
            --datasetIt;
        else if (datasetIt->first != _input[inputIt].first)
        {
            if (datasetIt == dataset.begin())
            {
                std::cout << "Error: no previous date available => " << _input[inputIt].first << std::endl;
                continue;
            }

            --datasetIt;
        }

        printValue = _input[inputIt].second * datasetIt->second;
        std::cout << _input[inputIt].first << " => " << _input[inputIt].first << " = " << printValue << std::endl;
    }
}