#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(" "), _grade(1){}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(1){
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy){
    *this = copy;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &copy ){
	if (this != &copy){
        if (copy.getGrade() > 150)
            throw GradeTooLowException();
        if (copy.getGrade() < 1)
            throw GradeTooHighException();
        _grade = copy.getGrade();
    }
	return (*this);
}

const std::string   Bureaucrat::getName() const {
    return _name;
}

int     Bureaucrat::getGrade()const{
    return _grade;
}

void    Bureaucrat::incrementGrade(){
    _grade--;
    if (_grade < 1)
        throw GradeTooHighException();
}

void    Bureaucrat::decrementGrade(){
    _grade++;
    if (_grade > 150)
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low.");
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &bureaucrat ){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}