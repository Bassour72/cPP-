#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
    Ice();                          // constructor
    Ice(const Ice& other);          // copy constructor
    Ice& operator=(const Ice& other); // copy assignment
    virtual ~Ice();                 // destructor

    AMateria* clone() const;        // must return new Ice
    void use(ICharacter& target);   // prints "* shoots an ice bolt at <name> *"
};

#endif /* ICE_HPP */

