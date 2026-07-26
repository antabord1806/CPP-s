#include "RPN.hpp"

RPN::RPN(void){}

RPN::RPN(const RPN &copy):_stack(copy._stack){}

RPN &RPN::operator=(const RPN &copy){
    if (this != &copy){
        _stack = copy._stack;
    }
    return *this;
}

RPN::~RPN(void){}

void    RPN::handlingInput(std::string input){
    std::istringstream stream(input);
    std::string token;

    if (input.empty())
        throw std::runtime_error("Error: Empty!");
    while (stream >> token){
        if (token[0] == ' ')
            continue;
        else if (std::isdigit(static_cast<unsigned char>(token[0])))
            _stack.push(token[0] - '0');
        else if (token[0] == '/' || token[0] == '+' || token[0] == '-' || token[0] == '*')
            operation(token[0]);
        else
            throw std::runtime_error ("Error: invalid input");
    }
    if (_stack.size() != 1)
        throw std::runtime_error ("Error: Invalid order of number or operands");
    std::cout << _stack.top() << std::endl;
}

void RPN::operation(char operand)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error: invalid operand placement");

    double right = _stack.top();
    _stack.pop();

    double left = _stack.top();
    _stack.pop();

    double result;

    if (operand == '+')
        result = left + right;
    else if (operand == '-')
        result = left - right;
    else if (operand == '*')
        result = left * right;
    else if (operand == '/')
    {
        if (right == 0)
            throw std::runtime_error("Error: division by zero");
        result = left / right;
    }
    else
        throw std::runtime_error("Error: invalid operand");

    _stack.push(result);
}