
#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap();                               // default constructor
    ClapTrap(const std::string &name);        // parameterized constructor
    ClapTrap(const ClapTrap &other);          // copy constructor
    ClapTrap &operator=(const ClapTrap &other); // copy assignment operator
    ~ClapTrap();                              // destructor

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Setters
    void setName(const std::string &name);
    void setHitPoints(unsigned int hitPoints);
    void setEnergyPoints(unsigned int energyPoints);
    void setAttackDamage(unsigned int attackDamage);

    // Getters
    const std::string &getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};

#endif /* CLAPTRAP_H */


