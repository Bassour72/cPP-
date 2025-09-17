
#include "Animal.hpp"

Animal::Animal(const std::string& t) : type(t) 
{
    std::cout << "Animal created: " << type << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) 
{
    std::cout << "Animal copied: " << type << std::endl;
}

Animal& Animal::operator=(const Animal& other)
 {
    type = other.type;
    return *this;
}

std::string Animal::getType() const 
{
    return type;
}

void Animal::setType(const std::string& t) 
{
    type = t;
}

void Animal::makeSound() const 
{
    std::cout << type << " makes a sound..." << std::endl;
}

Animal::~Animal() 
{
    std::cout << "Animal destroyed: " << type << std::endl;
}
