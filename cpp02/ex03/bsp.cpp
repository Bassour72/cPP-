#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = (b.getX() - a.getX()) * (point.getY() - a.getY())
                 - (b.getY() - a.getY()) * (point.getX() - a.getX());
    Fixed cross2 = (c.getX() - b.getX()) * (point.getY() - b.getY())
                 - (c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed cross3 = (a.getX() - c.getX()) * (point.getY() - c.getY())
                 - (a.getY() - c.getY()) * (point.getX() - c.getX());

    if (cross1 == 0 || cross2 == 0 || cross3 == 0)
        return false;

    if ((cross1 > 0 && cross2 > 0 && cross3 > 0) ||
        (cross1 < 0 && cross2 < 0 && cross3 < 0))
        return true;

    return false;
}
