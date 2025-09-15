#include "Fixed.hpp"

// ----------------- Constructors / Destructor -----------------
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}

Fixed::Fixed(const float value) : _value((int)roundf(value * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed::~Fixed() {}

// ----------------- Assignment -----------------
Fixed &Fixed::operator=(const Fixed &other) 
{
    if (this != &other)
        _value = other._value;
    return *this;
}

// ----------------- Getter / Setter -----------------
int Fixed::getRawBits(void) const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }

// ----------------- Conversion -----------------
float Fixed::toFloat(void) const { return (float)_value / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return _value >> _fractionalBits; }

// ----------------- Comparison operators -----------------
bool Fixed::operator<(const Fixed &other) const { return _value < other._value; }
bool Fixed::operator<=(const Fixed &other) const { return _value <= other._value; }
bool Fixed::operator>(const Fixed &other) const { return _value > other._value; }
bool Fixed::operator>=(const Fixed &other) const { return _value >= other._value; }
bool Fixed::operator==(const Fixed &other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed &other) const { return _value != other._value; }

// ----------------- Arithmetic operators -----------------
Fixed Fixed::operator+(const Fixed &other) const 
{
    Fixed temp;
    temp.setRawBits(_value + other._value);
    return temp;
}

Fixed Fixed::operator-(const Fixed &other) const 
{
    Fixed temp;
    temp.setRawBits(_value - other._value);
    return temp;
}

Fixed Fixed::operator*(const Fixed &other) const 
{
    Fixed temp;
    long long result = (long long)_value * (long long)other._value;
    temp.setRawBits((int)(result >> _fractionalBits));
    return temp;
}

Fixed Fixed::operator/(const Fixed &other) const 
{
    if (other.getRawBits() == 0)
    {
        std::cerr << "Error: Cannot divide by zero" << std::endl; // todo remove it
        return Fixed(0);
    }

    Fixed temp;
    long long numerator = ((long long)_value << _fractionalBits);
    temp.setRawBits((int)(numerator / other.getRawBits()));
    return temp;
}

// ----------------- Increment / Decrement -----------------
// Prefix
Fixed &Fixed::operator++() 
{ 
    ++_value; return *this; 
}
Fixed &Fixed::operator--() 
{ 
    --_value; return *this; 
}
// Postfix
Fixed Fixed::operator++(int) 
{ 
    Fixed temp(*this); ++_value; return temp; 
}
Fixed Fixed::operator--(int) 
{ 
    Fixed temp(*this); --_value; return temp; 
}

// ----------------- Min / Max -----------------
Fixed &Fixed::min(Fixed &a, Fixed &b) 
{ 
    if (a < b)
        return (a);
    else
        return (b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    if (a < b)
        return (a);
    else
        return (b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    if (a > b)
        return (a);
    else
        return (b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{ 
    if (a > b)
        return (a);
    else
        return (b);
}

// ----------------- Insertion ope
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}