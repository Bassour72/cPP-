#pragma once
#ifndef __WEAPON_HPP_
#define __WEAPON_HPP_

#include <string>

class Weapon
{
private:
	std::string	_type;

public:
	Weapon(std::string	type);
	const std::string&	getType(void);
	void setType(std::string type);
	~Weapon();
};

#endif /* __WEAPON_HPP__ */
