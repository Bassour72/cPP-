#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap :public FragTrap , public ScavTrap
{
private:
    // Data members
    std::string _name;
public:
    DiamondTrap(/* args */);
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    void whoAmI();
    ~DiamondTrap();
     void setName(const std::string &name);
     const std::string &getName() const;
};


#endif /* DIAMONDTRAP_HPP */
