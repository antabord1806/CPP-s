#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << std::endl << "--------------------------Test1: Shruberry OK---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 150);
        Intern rando;
        AForm* b = rando.makeForm(std::string("shrubbery creation"), "arvore");
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
        Bureaucrat a("Ze Manel", 10);
        Intern rando;
        AForm* b = rando.makeForm(std::string("robotomy request"), "robo");
        a.signForm(*b);
        a.executeForm(*b);
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
        Bureaucrat a("Ze Manel", 10);
        Intern rando;
        AForm* b = rando.makeForm(std::string("presidential pardon"), "pardon");
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test4: Form aleady signed---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 150);
        Intern rando;
        AForm* b = rando.makeForm(std::string("shrubbery creation"), "arvore");
        a.signForm(*b);
        a.executeForm(*b);
        a.signForm(*b);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test4: Unknown form---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 10);
        Intern rando;
        AForm* b = rando.makeForm(std::string("olarilolé"), "pardon");
        a.signForm(*b);
        a.executeForm(*b);
        std::cout << *b << std::endl;
        delete b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}