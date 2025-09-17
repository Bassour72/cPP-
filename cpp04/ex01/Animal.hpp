#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;

public:
    Animal(const std::string& t = "Animal");
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);

    std::string getType() const;
    void setType(const std::string& t);

    virtual void makeSound() const;
    virtual ~Animal();
};

#endif
