#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
    std::cout << "Dog created" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copied" << std::endl;
    _brain = new Brain(*other._brain); // deep copy
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog assigned" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << type << " says Bark!" << std::endl;
}
void Dog::addIdea(const std::string& idea) 
{
    _brain->setIdeas(idea);
}

void Dog::showLastIdea() const 
{
    std::cout << "Dog's last idea: " << _brain->getIdeas() << std::endl;
}

Dog::~Dog() 
{
    delete _brain;
    std::cout << "Dog destroyed" << std::endl;
}

