#include "Zombie.hpp"

Zombie  *zombieHorde(int n, std::string name){
    Zombie *hoard = new Zombie[n];

    for (int i = 0; i < n; i++)
        hoard[i].setName(name);
    return hoard;
}