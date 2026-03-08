#include "Zombie.hpp"

int main(void)
{
    int n = 5;
    Zombie *horde = zombieHorde(n, "joão");
    for (int i = 0; i < n; i++)
        horde->announce();
    delete[] horde;
    return 0;
}