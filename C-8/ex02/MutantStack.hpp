#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack(): std::stack<T>(){};
        MutantStack(const MutantStack &copy): std::stack<T>(){}
        ~MutantStack(){};
        MutantStack &operator=(const MutantStack &copy){
            if (*this != copy){
                std::stack<T>::operator=(copy)  ;
            }
            return *this;
        };

        iterator  begin(){
            return (this->c.begin()); }
        iterator  end(){
            return (this->c.end()); }
};


#endif