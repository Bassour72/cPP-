#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"
#include <iostream>
class ICharacter;
class AMateria
{

protected:
    std::string _type;
public:

    AMateria(std::string const & type);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    void setType(std::string &type);
    virtual ~AMateria();
};

#endif /* AMATERIA_HPP */
