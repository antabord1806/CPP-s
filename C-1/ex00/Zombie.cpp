#include "Zombie.hpp"

Zombie::Zombie(std::string name): z_name(name){
    std::cout << "New_Zombie: " << z_name << " was ceated" << std::endl;
}

Zombie::~Zombie(void){
    std::cout << "Zombie: " << z_name <<  " was destroyed" << std::endl;
}

void    Zombie::announce(void){
    std::cout << z_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
