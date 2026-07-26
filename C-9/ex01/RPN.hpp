#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <sstream>
#includ

class RPN{
    public:
        RPN(void);
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN(void);
        void    handlingInput(std::string arg);
    private:
        std::stack<double> _stack;
        void operation(char operand);
};

#endif