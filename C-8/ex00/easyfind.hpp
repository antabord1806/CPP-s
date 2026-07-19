#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

class NbNotFound: public std::exception{
    public:
        virtual const char * what() const throw(){
            return ("Didnt find it!");
        } 
};


template <typename T>
void    easyfind(T &hay, int needle){
    for (typename T::iterator it = hay.begin(); it != hay.end(); it++){
        if (*it == needle)
            return ;
    }
    throw NbNotFound();
}

#endif