#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    // Constructors
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);

    // Assignment operator
    ScavTrap &operator=(const ScavTrap &other);

    // Destructor
    ~ScavTrap();

    // Member functions
    void attack(const std::string &target); // Override
    void guardGate();                        // Special ability
    void setEnergy(unsigned int e);
unsigned int getEnergy() const;
};

#endif /* SCAVTRAP_HPP */

