#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void){
    {
        Weapon club = Weapon("big stick");
        HumanA bob = HumanA("Bob", club);
        bob.attack();
        club.setType("other stick");
        bob.attack();
    }
    {
        Weapon club = Weapon("giant stick");
        HumanB jim = HumanB("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("normal stick");
        jim.attack();
    }
    return 0;
}