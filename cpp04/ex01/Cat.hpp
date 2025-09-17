#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* _brain;

public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    void addIdea(const std::string& idea);
    void showLastIdea() const;
    void makeSound() const;
    ~Cat();
};

#endif

