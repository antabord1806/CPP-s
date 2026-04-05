#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    public:
        /*Increment/decrement*/
        Fixed operator++(int);
        Fixed &operator++();
        Fixed operator--(int);
        Fixed &operator--();

        /*Construct distruct*/
        Fixed(void);
        Fixed(Fixed const &copy);
        Fixed(const int i);
        Fixed(const float f);
        ~Fixed();

        /*comparassion*/
        bool operator<(const Fixed &copy) const;
        bool operator>(const Fixed &copy) const;
        bool operator==(const Fixed &copy) const;
        bool operator!=(const Fixed &copy) const;
        bool operator>=(const Fixed &copy) const;
        bool operator<=(const Fixed &copy) const;

        /*arithmetic*/
        Fixed operator+(const Fixed &copy) const;
        Fixed operator-(const Fixed &copy) const;
        Fixed operator*(const Fixed &copy) const;
        Fixed operator/(const Fixed &copy) const;
        Fixed &operator=(const Fixed copy);
        
        
        /*member functions*/
        int     getRawBits(void) const;
        void    setRawBits(const int raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;

        /*static member*/
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
    private:
        static const int _fractBits;
        int _fixedValue;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif