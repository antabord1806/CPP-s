#include "Phonebook.hpp"

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