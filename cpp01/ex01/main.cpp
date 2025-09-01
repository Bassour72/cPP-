#include "Zombie.hpp"


int main(void)
{
    Zombie *horde = zombieHorde(5, "toto");
    horde[0].announce();
    horde[1].announce();
    horde[2].announce();
    horde[3].announce();
    horde[4].announce();
    delete []horde;
    return 0;
}