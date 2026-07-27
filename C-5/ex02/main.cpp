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
        ShrubberyCreationForm form0("arvore");
        a.signForm(form0);
        a.executeForm(form0);
        std::cout << form0 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test2: Roboto OK---------------------" << std::endl;
    try
    {
        Bureaucrat c("Ze Maria", 10);
        RobotomyRequestForm form1("robot");
        c.signForm(form1);
        c.executeForm(form1);
        std::cout << form1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test3: President OK---------------------" << std::endl;
    try
    {
        Bureaucrat f("Ze Maria", 10);
        PresidentialPardonForm form2("presidential");
        f.signForm(form2);
        f.executeForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test4: Shruberry not enough---------------------" << std::endl;
    try
    {
        Bureaucrat a("Ze Manel", 150);
        ShrubberyCreationForm form3("arvore");
        a.signForm(form3);
        a.executeForm(form3);
        std::cout << form3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "--------------------------Test4: President alreadysigned---------------------" << std::endl;
    try
    {
        Bureaucrat f("Ze Maria", 10);
        PresidentialPardonForm form4("presidential");
        f.signForm(form4);
        f.executeForm(form4);
        f.signForm(form4);
        std::cout << form4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}