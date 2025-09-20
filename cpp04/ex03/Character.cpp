#include "Character.hpp"

Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : nullptr;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : nullptr;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            break;
        }
    }
}
void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) 
        return;
    inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4) return;
    if (inventory[idx])
        inventory[idx]->use(target);
}
