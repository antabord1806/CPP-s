#include "Zombie.hpp"

int main(void)
{
    Zombie *z = newZombie("Manel");
    z->announce();
    randomChump("Zé");
    delete z;
    return 0;
}