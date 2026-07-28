#include "Bureaucrat.hpp"

int main(void){
    std::cout << "-------------Test1: Too high------------------" << std::endl;
    try{
        Bureaucrat a("Ze Maria", -1);
        std::cout << a << std::endl;
    }
    catch(std::exception &e){    
        std::cout << "Exeption: " << e.what() << std::endl;
    }
    std::cout << "-------------Test2: Too low------------------" << std::endl;
    try{
        Bureaucrat a("Paulo", 151);
        std::cout << a << std::endl;
    }
    catch(std::exception &e){    
        std::cout << "Exeption: " << e.what() << std::endl;
    }
    std::cout << "--------------Test3: Incrmenting too much-----------------" << std::endl;
    try{
        Bureaucrat a("Sho Vitor", 3);
        for (int i = 0; i < 11; i++){
            a.incrementGrade();
            std::cout << a << std::endl;
        }
    }
    catch(std::exception &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------Test1: OK grade------------------" << std::endl;
    try{
        Bureaucrat a("Ze Mario", 10);
        std::cout << a << std::endl;
    }
    catch(std::exception &e){    
        std::cout << "Exeption: " << e.what() << std::endl;
    }
}