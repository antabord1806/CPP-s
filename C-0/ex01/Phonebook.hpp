
#include <iostream>
#include <cctype>

using namespace std;

class Contacts
{
    public:
        char *name;
        int  number;
};

class Phonebook
{
    private:
        Contacts contacts[8];
        int count;
    public:
        Phonebook();
        ~Phonebook();
        void addContact();
        void searchContact();
        void displayContact();
};
