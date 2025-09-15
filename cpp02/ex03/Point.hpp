#ifndef   POINT_HPP
#define   POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();                                   // default constructor
    Point(const float a, const float b);       // parameterized constructor
    Point(const Point &other);                 // copy constructor
    Point &operator=(const Point &other);      // copy assignment operator
    const Fixed &getX() const;                 // getter for x
    const Fixed &getY() const;                 // getter for y
    ~Point();                                  // destructor
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif /*POINT_HPP */
