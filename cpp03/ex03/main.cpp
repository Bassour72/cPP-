
#include "DiamondTrap.hpp"

int main()
{
    // Create a DiamondTrap with a custom name
    DiamondTrap dt("Diamondy");
    dt.setName("ffffff");
    // Test its ability
    dt.whoAmI();

    // Test inherited attack method (comes from ScavTrap)
    dt.attack("an enemy");

    // Test inherited FragTrap ability
    dt.highFivesGuys();

    // Test inherited ScavTrap ability
    dt.guardGate();

    // Destruction will be shown automatically
    return 0;
}

