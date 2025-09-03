#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>
#include <iostream>
#include <fstream>
class Harl
{
private:
	/* data */
	void	debug(void);    // prints the DEBUG message
	void	info(void);     // prints the INFO message
	void	warning(void);  // prints the WARNING message
	void	error(void);    // prints the ERROR message
	

public:
	Harl(/* args */);
	void complain(std::string level);

	~Harl();
};
#endif // __HARL_HPP__
