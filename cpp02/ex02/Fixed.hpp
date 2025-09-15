#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    // Constructors / Destructor
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed();

    // Assignment
    Fixed &operator=(const Fixed &other);

    // Getter / Setter
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison operators
    bool operator<(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment / Decrement
    Fixed &operator++();    // prefix ++
    Fixed &operator--();    // prefix --
    Fixed operator++(int);  // postfix ++
    Fixed operator--(int);  // postfix --

    // Min / Max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

};
    // Insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

