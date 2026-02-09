#ifndef phonebook
#define phonebook

using namespace std;

class Contacts
{
    public:

}

class Phonebook
{
    private:
        Contacts contacts[8];
        int count;
    public:
        Phonebook();
        ~Phonebook();
        addContact();
        searchContact();
        displayContact();
}

#endif 