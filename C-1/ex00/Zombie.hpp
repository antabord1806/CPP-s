
#include <iostream>
#include <string>
#include <memory>

class Zombie {
    public:
        Zombie(std::string name);
        ~Zombie(void);
        void    announce(void);
        
    private:
        std::string z_name;

        Zombie(void);
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

