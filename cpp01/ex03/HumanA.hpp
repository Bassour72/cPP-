#pragma once
#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	/* data */
	std::string _name;
	Weapon &_weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	std::string	getName(void);
	void setName(std::string name);
	void setWeapon(Weapon &weapon);
	void attack(void);
	Weapon& getWeapon(void);

	~HumanA();
};

#endif /* __HUMANA_HPP__*/