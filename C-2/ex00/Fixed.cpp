#include "Fixed.hpp"

static const int    _bits = 8;

Fixed::Fixed(void): _fixedpointvalue(0){
    std::cout<< "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy): _fixedpointvalue(0){
    (void)&copy;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed copy) {
    this->setRawBits(copy.getRawBits());
    return (*this);
}

void    Fixed::setRawBits(const int rawbits){
    this->_fixedpointvalue = rawbits;
}

int     Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedpointvalue);
}