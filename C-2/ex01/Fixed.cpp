#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed(): _fixedValue(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i): _fixedValue(i << _fractBits){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f): _fixedValue(roundf(f * (1 << _fractBits))){
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy): _fixedValue(copy._fixedValue){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed copy){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedValue = copy._fixedValue;
    return (*this);
}

int Fixed::toInt(void) const {
    return _fixedValue >> _fractBits;
}

float Fixed::toFloat(void) const {
    return ((float)_fixedValue / (1 << _fractBits));
}

void    Fixed::setRawBits(const int rawbits){
    _fixedValue = rawbits;
}

int     Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedValue);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &other){
    stream << other.toFloat();
    return stream;
}