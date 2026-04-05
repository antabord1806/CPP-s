#include "Point.hpp"

Point::Point(): x(0), y(0){
}

Point::Point(const float x, const float y): x(x), y(y){
}

Point::Point(Point const &copy): x(copy.x), y(copy.y){
}

Point::~Point(){
}

Point &Point::operator=(const Point copy){
    (void)copy;
    return *this;
}

int Point::getX() const{
    return x.getRawBits();
}

int Point::getY() const{
    return y.getRawBits();
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    int side1 = (point.getX() - b.getX()) * (a.getY() - b.getY()) - (a.getX() - b.getX()) * (point.getY() - b.getY());
    int side2 = (point.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (point.getY() - c.getY());
    int side3 = (point.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (point.getY() - a.getY());

    bool neg = (side1 < 0) && (side2 < 0) && (side3 < 0);
    bool pos = (side1 > 0) && (side2 > 0) && (side3 > 0);

    return (neg || pos);
}