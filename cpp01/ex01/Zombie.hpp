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
	Zombie();
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
    void setName(std::string name);
    std::string getName(void);
};

// free functions
Zombie* zombieHorde( int N, std::string name);

#endif
