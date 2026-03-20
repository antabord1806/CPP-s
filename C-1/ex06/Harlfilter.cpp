#include "Harlfilter.hpp"

Harlfilter::Harlfilter(){}

Harlfilter::~Harlfilter(){}

void    Harlfilter::complain(std::string level, int n){
    std::string options[] = {"DEBUG", "INFO", "ERROR", "WARNING"};
    void (Harlfilter::*ptr[5])() = {&Harlfilter::debug, &Harlfilter::info, &Harlfilter::error, &Harlfilter::warning, NULL};

    for (int i = 0; ptr[i]; i++){
        if (options[i] == level)
            filter(this->*ptr[i], n);
    }
}