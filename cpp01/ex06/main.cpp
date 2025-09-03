#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac == 2)
        harl.displayLevelMessage(av[1]);
    else
        std::cout << "Usage: ./harlFilter <level>" << std::endl;

    return 0;
}
