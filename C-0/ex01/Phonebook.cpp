#include "Phonebook.hpp"


Phonebook::Phonebook(): contacts(), count(0), max(8)
{
    std::cout << "construtor " << std::endl;
}

Phonebook::~Phonebook(){
    std::cout << "destrutor " << std::endl;
}

void Phonebook::addContact(void)
{
    if (count == max)
    {
        contacts[0] =
    }
}

int main(void)
{
    Phonebook phone;
    while (42)
    {
        std::string line;
        getline(std::cin, line);
        if (line == "add")
            phone.addContact();
        if (line == "search")
            phone.searchContact();
        if (line == "exit")
            break;
    }
}
