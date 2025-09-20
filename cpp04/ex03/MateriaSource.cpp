#include "MateriaSource.hpp"

// Constructor
MateriaSource::MateriaSource() : _idx(0)
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

// Copy constructor (deep copy)
MateriaSource::MateriaSource(const MateriaSource& other) : _idx(other._idx)
{
    for (int i = 0; i < 4; i++)
        _materia[i] = other._materia[i] ? other._materia[i]->clone() : NULL;
}

// Assignment operator (deep copy)
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materia[i])
            {
                delete _materia[i];
                _materia[i] = NULL;
            }
            _materia[i] = other._materia[i] ? other._materia[i]->clone() : NULL;
        }
        _idx = other._idx;
    }
    return *this;
}

// Destructor
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (_materia[i])
            delete _materia[i];
}

// Learn a Materia
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m || _idx >= 4)
        return;

    _materia[_idx] = m;
    _idx++;
}

// Create a Materia by type
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i]->clone();
    }
    return NULL; // type unknown
}
