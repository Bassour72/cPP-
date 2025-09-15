
#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

// copy assignment operator cannot be implemented because x and y are const
 Point &Point::operator=(const Point &other) 
 { 
    (void)other;
    return *this; 
}

const Fixed &Point::getX() const { return x; }
const Fixed &Point::getY() const { return y; }


Point::~Point()
{
}