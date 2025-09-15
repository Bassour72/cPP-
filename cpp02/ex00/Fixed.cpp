#include "Fixed.hpp"

Fixed::Fixed(/* args */)
{
    std :: cout << "Default constructor called" << std :: endl;
    _value = 0;
    
}
Fixed::Fixed(const Fixed& other)
{
    std :: cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

 
Fixed&   Fixed::operator=(const Fixed& other)
{
    std :: cout << "Copy assignment operator called"<< std :: endl;
    this->_value = other.getRawBits(); // Check why this work  this->_value = other._v
    return (*this);
}
int     Fixed::getRawBits( void ) const
{
    std :: cout << "getRawBits member function called" << std::endl;
    
    return (_value);
}
void    Fixed::setRawBits( int const raw )
{
    _value = raw;
}

