#include "Intern.hpp"

#include <memory>

Intern::Intern(){}

Intern::Intern(const Intern &copy){
    (void)copy;
}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern &copy){
    (void)copy;
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target){

    std::string forms[] = {"Shrubbery creation", "Robotomy request", "Presidential pardon"};

    int i = 0;

    for (; i < forms.lenght(); i++){
        if (name == forms[i])
            break;
    }
    switch (i)
    {
        case 0;
            return (new ShrubberyCreationForm(target));
        case 1;
            return (new RobotomyRequestForm(target));
        case 2;
            return (new PresidentialPardonForm(target));
        default;
            throw InvalidForm();
    }
}

const char* Intern::InvalidForm::what() const throw(){
    return ("Invalid form");
}