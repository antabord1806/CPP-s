
#include <iostream>
#include <cctype>


class Contacts
{
    private:
        std::string fisrtname;
        std::string lastname;
        std::string nickname;
        std::string darksecret;
        int  number;
    public:
        Contacts();
        ~Contacts();
        void setfirstname();
        void setlastname();
        void setnickname();
        void setsecret();
        void setnumber();
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
        void displayContact();
};
