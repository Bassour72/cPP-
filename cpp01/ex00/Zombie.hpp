#pragma once
#ifndef __ZOMBIE__H_
#define __ZOMBIE__H_

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string _name;
public:
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
    void setName(std::string name);
    std::string getName(void);
};

// free functions
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
