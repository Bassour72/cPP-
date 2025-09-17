#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) 
{
    std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << type << " says Meow!" << std::endl;
}

Cat::~Cat() 
{
    std::cout << "Cat destroyed" << std::endl;
}
