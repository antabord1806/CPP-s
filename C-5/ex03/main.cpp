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

    AForm* form = NULL;
    Intern rando;

    std::cout << std::endl << "--------------------------Test1: Shruberry OK---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 10);
        form = rando.makeForm(std::string("Shrubbery creation"), "arvore");
        if (form){
            std::cout << "intern creates " << *form << std::endl;
            a.signForm(*form);
            a.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        delete form;
        form = NULL;
    }

    std::cout << std::endl << "--------------------------Test2: Roboto OK---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 10);
        form = rando.makeForm(std::string("Robotomy request"), "robo");
        if (form){
            std::cout << "intern creates " << *form << std::endl;
            a.signForm(*form);
            a.executeForm(*form);
            delete form;
            form = NULL;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        delete form;
        form = NULL;
    }

    std::cout << std::endl << "--------------------------Test3: President OK---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 2);
        form = rando.makeForm(std::string("Presidential pardon"), "pardon");
        if (form){
            std::cout << "intern creates " << *form << std::endl;
            a.signForm(*form);
            a.executeForm(*form);
            delete form;
            form = NULL;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        delete form;
        form = NULL;
    }

    std::cout << std::endl << "--------------------------Test4: Form aleady signed---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 10);
        form = rando.makeForm(std::string("Shrubbery creation"), "arvore");
        if (form){
            std::cout << "intern creates " << *form << std::endl;
            a.signForm(*form);
            a.executeForm(*form);
            a.signForm(*form);
            delete form;
            form = NULL;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        delete form;
        form = NULL;
    }

    std::cout << std::endl << "--------------------------Test4: Unknown form---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 10);
        AForm* form = rando.makeForm(std::string("olarilolé"), "pardon");
        if (form){
            std::cout << "intern creates " << *form << std::endl;
            a.signForm(*form);
            a.executeForm(*form);
            delete form;
            form = NULL;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        delete form;
        form = NULL;
    }
    if (form)
        delete form;
    return 0;
}