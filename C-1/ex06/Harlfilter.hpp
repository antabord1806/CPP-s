#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

#include <iostream>

class Harlfilter{
    public:
        Harlfilter(void);
        ~Harlfilter(void);
        void    complain(std::string level, int n);
    private:
        void    filter(Harlfilter *ptr, int n);
        void    info(void);
        void    error(void);
        void    debug(void);
        void    warning(void);
};

#endif