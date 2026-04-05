#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed(void);
        Fixed(Fixed const &copy);
        Fixed(const int i);
        Fixed(const float f);
        ~Fixed();
        Fixed &operator=(const Fixed copy);
        int     getRawBits(void) const;
        void    setRawBits(const int raw);
        float toFloat( void ) const;
        int toInt( void ) const;
    private:
        static const int _fractBits;
        int _fixedValue;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif