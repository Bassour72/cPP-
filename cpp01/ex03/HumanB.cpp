#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

std::string HumanB::getName(void)
{
	return _name;
}

void HumanB::setName(std::string name)
{
	_name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

Weapon &HumanB::getWeapon(void)
{
	return *_weapon;
}

void HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon!" << std::endl;
}

HumanB::~HumanB() {}
