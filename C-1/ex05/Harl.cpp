#include "Harl.hpp"

Harl::Harl(void){ }

Harl::~Harl(void){}

void    Harl::complain(std::string level){  
    std::string levels[] = {"INFO", "WARNING", "ERROR", "DEBUG"};
    void (Harl::*ptr[5])() = {&Harl::info, &Harl::warning, &Harl::error, &Harl::debug, NULL};
    for (int i = 0; ptr[i]; i++){
        if (levels[i] == level){
            (this->*ptr[i])();
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void    Harl::debug(void){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::error(void){
    std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void    Harl::warning(void){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

