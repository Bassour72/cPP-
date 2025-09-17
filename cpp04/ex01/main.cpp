#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <libc.h>
void f(void){system("leaks  ./Animal");}
int main()
{
    atexit(f);
//   Animal* animals[10];

//     for (size_t i = 0; i < 10; i++) {
//         if (i < 5)
//             animals[i] = new Dog();
//         else
//             animals[i] = new Cat();
//     }
//     for (size_t i = 0; i < 10; i++) {
//         animals[i]->makeSound();
//     }
//     for (size_t i = 0; i < 10; i++) {
//         delete animals[i];
//     }

    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
return 0;
}