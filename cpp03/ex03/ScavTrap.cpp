#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default")
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " has been created (default)!\n";
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " has been created!\n";
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << getName() << " copied!\n";
}

// Assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other); // Use base class assignment
    }
    std::cout << "ScavTrap " << getName() << " assigned!\n";
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " destroyed!\n";
}

// Attack function override
void ScavTrap::attack(const std::string &target)
{
    if (getHitPoints() == 0 || getEnergyPoints() == 0)
        return;
    std::cout << "ScavTrap " << getName() << " fiercely attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!\n";
    setEnergyPoints(getEnergyPoints() - 1);
}

// Special ability
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!\n";
}
void ScavTrap::setEnergy(unsigned int e) { setEnergyPoints(e); }
unsigned int ScavTrap::getEnergy() const { return getEnergyPoints(); }
