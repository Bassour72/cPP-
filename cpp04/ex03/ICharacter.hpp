#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
class ICharacter
{
private:
    // Data members

public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

ICharacter::ICharacter(/* args */)
{

};

ICharacter::~ICharacter(/* args */)
{

};
#endif /* ICHARACTER_HPP */
