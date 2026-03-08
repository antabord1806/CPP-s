#include "Zombie.hpp"

Zombie::Zombie(void): z_names(){
    std::cout << "Zombie was created!" << std::endl;
}

Zombie::~Zombie(void){
    std::cout << "Zombie " << z_names << " was destroyed!" << std::endl;
}

void    Zombie::announce(void){
    std::cout << z_names << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name){
    z_names = name;
}
