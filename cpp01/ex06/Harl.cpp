#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::eLevel Harl::_getLevel(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return static_cast<eLevel>(i);
    }
    return INVALID;
}

void Harl::complain(std::string level)
{
    typedef void (Harl::*PointerToFunction)(void);
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    PointerToFunction funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*funcs[i])();
            break;
        }
    }
}

void Harl::displayLevelMessage(std::string level)
{
    eLevel l = _getLevel(level);

    switch (l)
    {
    case DEBUG:
        complain("DEBUG");
    case INFO:
        complain("INFO");
    case WARNING:
        complain("WARNING");
    case ERROR:
        complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

Harl::~Harl() {}
