#include <iostream>
#include <memory>

class Zombie{
    public:
        Zombie();
        ~Zombie(void);
        void    announce(void);
        void    setName(std::string name);
    private:
        std::string z_names;
};

Zombie  *zombieHorde(int n, std::string name);
Zombie  *newZombie(std::string name);
