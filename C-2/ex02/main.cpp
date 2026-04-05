#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    const Fixed &d = a;
    const Fixed e = b;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << Fixed::max( d, e ) << std::endl;
    std::cout << Fixed::min( d, e ) << std::endl;
    return 0;
}