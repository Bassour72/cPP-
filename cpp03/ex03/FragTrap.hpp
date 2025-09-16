#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
public:
    // Constructors
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);  // Copy constructor

    // Destructor
    ~FragTrap();

    // Assignment operator
    FragTrap &operator=(const FragTrap &other);

    // FragTrap specific function
    void highFivesGuys(void);
};

#endif /* FRAGTRAP_HPP */
