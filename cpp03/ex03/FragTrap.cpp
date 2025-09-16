#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap()
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    setName("Default");
    std::cout << "FragTrap " << getName() << " has been created!" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " has been created!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << getName() << " has been copied!" << std::endl;
}

// Assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);  // استخدم assignment من ClapTrap
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " has been destroyed!" << std::endl;
}

// FragTrap specific function
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " requests a positive high five! ✋" << std::endl;
}
