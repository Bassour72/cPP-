#include "Zombie.hpp"


int main(void)
{
    Zombie z("FOO");
    z.announce();
    Zombie *zz = newZombie("TOO");
    zz->announce();
    Zombie* z1 = newZombie("Bob");
    z1->announce();
    delete z1;
    delete zz;
    return 0;
}