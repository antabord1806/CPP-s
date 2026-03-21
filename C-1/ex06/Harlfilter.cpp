#include "Harlfilter.hpp"

Harlfilter::Harlfilter(){}

Harlfilter::~Harlfilter(){}

void    Harlfilter::complain(std::string level){
    std::string options[] = {"DEBUG", "INFO", "ERROR", "WARNING"};
    void (Harlfilter::*ptr[5])() = {&Harlfilter::debug, &Harlfilter::info, &Harlfilter::error, &Harlfilter::warning, NULL};

    for (int i = 0; ptr[i]; i++){
        if (options[i] == level){
            for (int j = i; ptr[j]; j++)
                (this->*ptr[j])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}

void    Harlfilter::debug(void){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harlfilter::info(void){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harlfilter::error(void){
    std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void    Harlfilter::warning(void){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

