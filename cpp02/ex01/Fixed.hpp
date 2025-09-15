
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _value;                                // raw fixed-point value
    static const int _fractionalBits = 8;      // number of fractional bits

public:
    Fixed();                                   // default constructor
    Fixed(const int value);                    // constructor from int
    Fixed(const float value);                  // constructor from float
    Fixed(const Fixed &other);                 // copy constructor
    Fixed &operator=(const Fixed &other);      // copy assignment
    ~Fixed();                                  // destructor

    int getRawBits(void) const;                // get raw value
    void setRawBits(int const raw);            // set raw value

    float toFloat(void) const;                 // convert to float
    int toInt(void) const;                     // convert to int
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
