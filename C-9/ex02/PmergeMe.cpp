#include "PmergeMe.hpp"

pMerge::pMerge(){}

pMerge::pMerge(const pMerge &copy): _vec(copy._vec), _deque(copy._deque){}

pMerge::~pMerge(){}

pMerge &pMerge::operator=(const pMerge &copy){
    if (this != &copy){
        _vec = copy._vec;
        _deque = copy._deque;
    }
    return *this;
}

void    pMerge::handlingInput(std::string &input){

    std::istringstream stream(input);
    std::string token;
    long long value;
    bool    doneFirst = false;
    int first;

    while (stream >> token){
        std::istringstream converter(token);
        char extra;

        if (!(converter >> value) || converter >> extra)
            throw std::runtime_error("Error: Only numbers");
        if (value > INT_MAX || value < 0)
            throw std::runtime_error("Error: Cant fit in int or <0");
        if (!doneFirst){
            first = static_cast<int>(value);
            doneFirst = true;
        }
        else{
            _vec.push_back(std::make_pair(first, static_cast<int>(value)));
            _deque.push_back(std::make_pair(first, static_cast<int>(value)));
            doneFirst = false;
        }
    }
    organizingPairs(_vec);
    organizingPairs(_deque);

    fordJhonson(_vec);
    fordJhonson(_deque);

}

std::vector<std::size_t> jacobsthalOrder(std::size_t count)
{
    std::vector<std::size_t> order;

    if (count <= 1)
        return order;

    std::size_t previousJacob = 1;
    std::size_t currentJacob = 3;
    std::size_t previousLimit = 1;

    while (previousLimit < count)
    {
        std::size_t currentLimit = currentJacob;

        if (currentLimit > count)
            currentLimit = count;

        for (std::size_t i = currentLimit; i > previousLimit; --i)
            order.push_back(i - 1);

        previousLimit = currentLimit;

        std::size_t nextJacob = currentJacob + 2 * previousJacob;

        previousJacob = currentJacob;
        currentJacob = nextJacob;
    }

    return order;
}

