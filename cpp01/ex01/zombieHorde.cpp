#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    Zombie* z = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
       /// name.push_back('0' + i);// this for deb
        z[i].setName(name);
    }
    return z;
}
