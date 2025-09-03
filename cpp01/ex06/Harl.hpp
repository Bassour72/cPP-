#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>
#include <iostream>



class Harl
{
private:
	enum eLevel
	{
		DEBUG = 0,
		INFO,
		WARNING,
		ERROR,
		INVALID
	};
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    eLevel _getLevel(std::string level);

public:
    Harl();
    void complain(std::string level);
    void displayLevelMessage(std::string level);
    ~Harl();
};

#endif // __HARL_HPP__
