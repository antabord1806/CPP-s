#include "Phonebook.hpp"

Phonebook::Phonebook(): contacts(), max(8) , count(0)
{
    std::cout << "Phonebook construido" << std::endl;
}

Phonebook::~Phonebook(){
    std::cout << "Phonebook destruido" << std::endl;
}

void Phonebook::addContact(void){
    if (count == max)
        this->contacts[0].updateContact();
    else
    {
        this->contacts[count].updateContact();
        count++;
    }
}


void Phonebook::searchContact(void){
    int index = 0;
    std::cout << "All contacts:" << std::endl;
    while (index < 8)
    {
        std::string line;
        std::cout << std::setw(10) << index << "|";
        std::cout << std::setw(10) << contacts[index].getfirstname() << "|";
        std::cout << std::setw(10) << contacts[index].getlastname() << "|";
        std::cout << std::setw(10) << contacts[index].getnickname() << "|";
        std::cout << std::endl;
        index++;
    }
}

