#include "Weapon.hpp"

Weapon::Weapon(std::string name): _type(name){
    std::cout << name << " was created!" << std::endl;
}

Weapon::~Weapon(){
    std::cout << _type << " was destroyed!" << std::endl;
}

void    Weapon::setType(std::string type){
    _type = type;
}

const   std::string &Weapon::getType(){
    return (_type);
}