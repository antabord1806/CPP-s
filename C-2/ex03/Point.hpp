#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point(Point const &copy);
        Point &operator=(const Point copy);
        ~Point();
        int getX() const;
        int getY() const;
        private:
        const Fixed x;
        const Fixed y;
};
    
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif