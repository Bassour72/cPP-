#include "Fixed.hpp"

Fixed::Fixed(/* args */)
{
    Fixed::_integer = 0;
    
}
Fixed::Fixed(Fixed &fixed)
{
    *this = fixed;
}
Fixed::~Fixed()
{
}

 
void    Fixed:: operator=(Fixed &fixed)
{
    *this = fixed;
}
int     Fixed::getRawBits( void ) const
{
    
}
void    Fixed::setRawBits( int const raw )
{

}