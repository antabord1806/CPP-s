#include "Phonebook.hpp"

Contacts::Contacts(){
}

Contacts::~Contacts(){
}

void Contacts::updateContact(){
    std::string sub;
    std::string line;
    std::cout << "Firstname:" << std::endl;
    std::getline(std::cin, line);
    if (line.length() > 10)
        sub = line + '.';
    this->firstname = line;
    std::cout << "Number:" << std::endl;
    std::getline(std::cin, line);
    if (line.length() > 10)
        sub = line.substr(0, 9) + ".";
    this->number = line;
    std::cout << "Lastname:" << std::endl;
    std::getline(std::cin, line);
    if (line.length() > 10)
        sub = line.substr(0, 9) + ".";
    this->lastname = line;
    std::cout << "Nickname:" << std::endl;
    std::getline(std::cin, line);
    if (line.length() > 10)
        sub = line.substr(0, 9) + ".";
    this->nickname = line;
    std::cout << "Darksecret:" << std::endl;
    std::getline(std::cin, line);
    if (line.length() > 10)
        sub = line.substr(0, 9) + ".";
    this->darksecret = line;
}

std::string Contacts::getfirstname(){
    return (this->firstname);
}

std::string Contacts::getlastname(){
    return (this->lastname);
}

std::string Contacts::getnickname(){
    return (this->nickname);
}