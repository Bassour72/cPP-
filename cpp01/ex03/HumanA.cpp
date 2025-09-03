#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	setName(name);
	setWeapon(weapon); //
}

std::string	HumanA::getName(void)
{
	return (_name);
}
void HumanA::setName(std::string name)
{
	(_name = name);
}

void HumanA::setWeapon(Weapon &weapon)
{
	(_weapon = weapon);
}

Weapon& HumanA::getWeapon(void)
{
	return (_weapon);
}
void HumanA::attack(void)
{
	std :: cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
}