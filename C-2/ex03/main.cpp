#include "Point.hpp"

int main(void){
    Point a(1, 1);
    Point b(5, 5);
    Point c(6, 10);
    Point point(0, 0);

    switch (bsp(a, b, c, point))
    {
        case true:
            std::cout << "Inside the triangle" << std::endl;
            break;
        case false:
            std::cout << "Outside the triangle!" << std::endl;
            break;
    }
    return 0;
}