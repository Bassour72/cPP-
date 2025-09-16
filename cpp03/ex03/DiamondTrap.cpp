#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default")
{
    setHitPoints(FragTrap::getHitPoints());
    setEnergyPoints(ScavTrap::getEnergyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap " << _name << " has been created!\n";
}

// Constructor with name
DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
    setHitPoints(FragTrap::getHitPoints());
    setEnergyPoints(ScavTrap::getEnergyPoints());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap " << _name << " has been created!\n";
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), _name(other._name)
{
    setHitPoints(other.getHitPoints());
    setEnergyPoints(other.getEnergyPoints());
    setAttackDamage(other.getAttackDamage());
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

// Special ability
void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name
              << " | ClapTrap name: " << ClapTrap::getName()
              << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " has been destroyed!\n";
}

// Getter & Setter
const std::string &DiamondTrap::getName() const { return _name; }
void DiamondTrap::setName(const std::string &name) { _name = name; }
