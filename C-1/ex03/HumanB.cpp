#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {
    std::cout << _name << " was created emptyhanded!" << std::endl;
}

HumanB::~HumanB(){
    std::cout << _name << " was destroyed!" << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon){
    _weapon = &weapon;
}

void    HumanB::attack(){
    std::cout << _name << " attacks using their " << _weapon->getType() << std::endl;
}