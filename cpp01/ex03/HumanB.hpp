#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon; // pointer, starts as nullptr

public:
	HumanB(std::string name);

	std::string getName(void);
	void setName(std::string name);

	void setWeapon(Weapon &weapon);
	Weapon &getWeapon(void);

	void attack(void);

	~HumanB();
};

#endif /* __HUMANB_HPP__ */
