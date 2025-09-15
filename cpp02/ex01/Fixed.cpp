#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : _value(0) 
{
    printf("ADDRES [%p] \n", (void*)this);
    std :: cout << "Default constructor called" << std :: endl;
}

// Int constructor
Fixed::Fixed(const int value) 
{
     printf("ADDRES [%p] \n", (void*)this);
    std :: cout << "Int constructor called" << std :: endl;
    _value = value << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float value) 
{
     printf("ADDRES [%p] \n", (void*)this);
    std :: cout << "Float constructor called"<< std :: endl;
    _value = (int)roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) 
{
    std :: cout << "Copy constructor called" << std ::endl;
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) 
{
    std :: cout << "Copy assignment operator called" << std :: endl;
    if (this != &other)
        _value = other._value;
    return *this;
}

// Destructor
Fixed::~Fixed() 
{
     printf("ADDRES [%p] \n", (void*)this);
    std :: cout << " | " << _value << std :: endl;
    std :: cout << "Destructor called"<< std :: endl;
}

// Getter
int Fixed::getRawBits(void) const
 {
    return _value;
}

// Setter
void Fixed::setRawBits(int const raw) 
{
    _value = raw;
}

// Convert to float
float Fixed::toFloat(void) const 
{
    return (float)_value / (1 << _fractionalBits);
}

// Convert to int
int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
    out << fixed.toFloat();
    return out;
}
