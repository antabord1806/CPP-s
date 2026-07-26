#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << std::endl << "--------------------------Test1: Shruberry OK---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 10);
        AForm* b = new ShrubberyCreationForm("arvore");
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test2: Roboto OK---------------------" << std::endl;
    try
    {
        Bureaucrat c("Ze Maria", 10);
        AForm* b = new RobotomyRequestForm("robot");
        c.signForm(*b);
        c.executeForm(*b);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test3: President OK---------------------" << std::endl;
    try
    {
        Bureaucrat f("Ze Maria", 10);
        AForm* b = new PresidentialPardonForm("presidential");
        f.signForm(*b);
        f.executeForm(*b);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test4: Shruberry not enough---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 150);
        AForm* b = new ShrubberyCreationForm("arvore");
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test4: President alreadysigned---------------------" << std::endl;
    try
    {
        Bureaucrat f("Ze Maria", 10);
        AForm* b = new PresidentialPardonForm("presidential");
        f.signForm(*b);
        f.executeForm(*b);
        f.signForm(*b);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}