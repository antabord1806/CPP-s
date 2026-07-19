#include "MutantStack.hpp"

int main()
{
    std::cout << "=====Mstack=====" << std::endl;
    MutantStack<int> mstack;
    std::cout << "Pushed 5" << std::endl;
    std::cout << "Pushed 17" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "======Top node======" << std::endl;
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "=====Popped top node======" << std::endl;
    std::cout << "Current size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}