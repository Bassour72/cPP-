#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* _brain;

public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    void addIdea(const std::string& idea);
    void showLastIdea() const;
    void makeSound() const;
    ~Dog();
};

#endif
