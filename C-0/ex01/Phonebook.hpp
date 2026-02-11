
#include <iostream>
#include <iomanip>
#include <cctype>


class Contacts
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string darksecret;
        std::string number;
    public:
        Contacts();
        ~Contacts();
        void updateContact();
        std::string getfirstname();
        std::string getlastname();
        std::string getnickname();
};

class Phonebook
{
    private:
        Contacts contacts[8];
        int max;
        int count;
    public:
        Phonebook();
        ~Phonebook();
        void addContact();
        void replaceContact();
        void searchContact();
};
