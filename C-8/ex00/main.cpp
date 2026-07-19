#include "easyfind.hpp"

int main(void){
    try{
        std::cout << "=============std::vector==============" << std::endl;
        std::vector<int> vect;
        vect.push_back(10);
        vect.push_back(50);
        vect.push_back(-8);
        vect.push_back(515);
        vect.push_back(4);
        vect.push_back(22);
        easyfind(vect, 4);
        std::cout << "Found it!" << std::endl;
    }
    catch(const std::exception& e){
        std::cout << "Exeption: " << e.what() << std::endl;
    }
    try{
        std::cout << "=============std::list==============" << std::endl;
        std::list<int> lst;
        lst.push_back(20);
        lst.push_back(-523);
        lst.push_back(14);
        lst.push_back(2);
        lst.push_back(0);
        easyfind(lst, 4);
        std::cout << "Found it!" << std::endl;
    }
    catch(const std::exception& e){
        std::cout << "Exeption: " << e.what() << std::endl;
    }
    try{
        std::cout << "=============std::deque==============" << std::endl;
        std::deque<int> deque;
        deque.push_back(20);
        deque.push_back(-523);
        deque.push_back(14);
        deque.push_back(2);
        deque.push_back(0);
        easyfind(deque, 2);
        std::cout << "Found it!" << std::endl;
    }
    catch(const std::exception& e){
        std::cout << "Exeption: " << e.what() << std::endl;
    }
}