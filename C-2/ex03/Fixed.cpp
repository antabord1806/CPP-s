#include "Fixed.hpp"

const int Fixed::_fractBits = 8;


/*--------------------Construct Distruct--------------------*/
Fixed::Fixed(): _fixedValue(0){
}

Fixed::Fixed(const int i): _fixedValue(i << _fractBits){
}

Fixed::Fixed(const float f): _fixedValue(roundf(f * (1 << _fractBits))){
}

Fixed::Fixed(Fixed const &copy): _fixedValue(copy._fixedValue){
}

Fixed::~Fixed(){
}

/*--------------------Increment/decrement--------------------*/

Fixed Fixed::operator++(int){
    Fixed tmp(*this);
    _fixedValue += 1;
    return tmp;
}

Fixed &Fixed::operator++(){
    _fixedValue += 1;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    _fixedValue -= 1;
    return tmp;
}

Fixed &Fixed::operator--(){
    _fixedValue -= 1;
    return *this;
}


/*--------------------Comparassion--------------------*/

bool Fixed::operator<(const Fixed &copy) const{
    return _fixedValue < copy._fixedValue;
}

bool Fixed::operator>(const Fixed &copy) const{
    return _fixedValue > copy._fixedValue;
}

bool Fixed::operator==(const Fixed &copy) const{
    return _fixedValue == copy._fixedValue;
}
 
bool Fixed::operator!=(const Fixed &copy) const{
    return _fixedValue != copy._fixedValue;
}

bool Fixed::operator>=(const Fixed &copy) const{
    return _fixedValue >= copy._fixedValue;
}

bool Fixed::operator<=(const Fixed &copy) const{
    return _fixedValue <= copy._fixedValue;
}

/*--------------------Arithmetic--------------------*/

Fixed Fixed::operator*(const Fixed &copy) const{
    Fixed result;
    result.setRawBits((this->_fixedValue * copy._fixedValue) >> _fractBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &copy) const{
    if (copy._fixedValue == 0)
        throw std::runtime_error("Division by zero");
    Fixed result;
    result.setRawBits((this->_fixedValue << _fractBits) / copy._fixedValue);
    return (result);
}

Fixed Fixed::operator+(const Fixed &copy) const{
    Fixed result;
    result.setRawBits(this->_fixedValue + copy._fixedValue);
    return (result);
}

Fixed Fixed::operator-(const Fixed &copy) const{
    Fixed result;
    result.setRawBits(this->_fixedValue - copy._fixedValue);
    return (result);
}

Fixed &Fixed::operator=(Fixed copy){
    _fixedValue = copy._fixedValue;
    return (*this);
}

/*--------------------static member--------------------*/


const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    if (a > b)
        return b;
    else
        return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    if (a < b)
        return b;
    else
        return a;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
    if (a > b)
        return b;
    else
        return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    if (a < b)
        return b;
    else
        return a;
}


/*--------------------Member functions--------------------*/

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
    return (_fixedValue);
}

/*--------------------------------------------------------*/

std::ostream &operator<<(std::ostream &stream, const Fixed &other){
    stream << other.toFloat();
    return stream;
}