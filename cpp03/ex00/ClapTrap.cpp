#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap " << _name << " has been copied!" << std::endl;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

// Attack function
void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot attack. No hit points or energy left!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
        return;
    }
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

// Repair function
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot repair itself. No hit points or energy left!" << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
}

// Setters
void ClapTrap::setName(const std::string &name) { _name = name; }
void ClapTrap::setHitPoints(unsigned int hitPoints) { _hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(unsigned int energyPoints) { _energyPoints = energyPoints; }
void ClapTrap::setAttackDamage(unsigned int attackDamage) { _attackDamage = attackDamage; }

// Getters
const std::string &ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }
