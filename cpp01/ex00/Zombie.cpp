#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << _name << " constructed\n";
}

Zombie::~Zombie()
{
    std::cout << _name << " destroyed\n";
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) 
{
     _name = name; 
}
std::string Zombie::getName(void) 
{ 
    return _name; 
}



