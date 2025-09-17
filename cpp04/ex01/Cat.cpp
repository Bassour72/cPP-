#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    std::cout << "Cat created" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) 
{
    std::cout << "Cat copied" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "Cat assigned" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << type << " says Meow!" << std::endl;
}

void Cat::addIdea(const std::string& idea) 
{
    _brain->setIdeas(idea);
}

void Cat::showLastIdea() const 
{
    std::cout << "Cat's last idea: " << _brain->getIdeas() << std::endl;
}

Cat::~Cat() 
{
    delete _brain;
    std::cout << "Cat destroyed" << std::endl;
}
