#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTrap ===\n";
    ClapTrap ct1("CT-One");
    ct1.attack("Target-A");
    ct1.takeDamage(5);
    ct1.beRepaired(3);

    std::cout << "\n=== Creating ScavTrap ===\n";
    ScavTrap st1("ST-One");
    st1.attack("Target-B");   // overridden attack()
    st1.guardGate();          // special ability

    std::cout << "\n=== Copy & Assignment ===\n";
    ScavTrap st2 = st1;       // copy constructor
    ScavTrap st3;
    st3 = st1;                 // assignment operator

    std::cout << "\n=== Testing energy/hit points ===\n";
    st1.setEnergy(0);
    st1.attack("Target-C");    // should do nothing

    return 0;
}


