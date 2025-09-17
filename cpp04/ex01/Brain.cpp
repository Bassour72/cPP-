#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain constructed" << std::endl;
    setIndexIdeas(0);
}

Brain::Brain(const Brain& other) 
{
    std::cout << "Brain copied" << std::endl;
    for (int i = 0; i < _MaxIndexIdeas; i++) 
    {
        this->_ideas[i] = other._ideas[i];
    }
    this->_indexIdeas = other._indexIdeas;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assigned" << std::endl;
    if (this != &other) 
    {
        for (int i = 0; i < _MaxIndexIdeas; i++) 
        {
            this->_ideas[i] = other._ideas[i];
        }
        this->_indexIdeas = other._indexIdeas;
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Brain destroyed" << std::endl;
}

const std::string& Brain::getIdeas() const 
{
    if (_indexIdeas == 0) 
    {
        static std::string empty = "";
        return empty;
    }
    return (this->_ideas[_indexIdeas - 1]);
}

void Brain::setIdeas(const std::string &str) 
{
    if (_indexIdeas < _MaxIndexIdeas) 
    {
        _ideas[_indexIdeas] = str;
        setIndexIdeas(getIndexIdeas() + 1);
    } 
    else 
    {
        _indexIdeas = 0;
        _ideas[_indexIdeas] = str;
        setIndexIdeas(getIndexIdeas() + 1);
    }
}

int Brain::getIndexIdeas() const
{
    return _indexIdeas;
}

void Brain::setIndexIdeas(int index) 
{
    _indexIdeas = index;
}
