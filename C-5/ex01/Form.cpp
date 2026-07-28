/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:53:59 by antabord          #+#    #+#             */
/*   Updated: 2026/05/27 10:57:25 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name(""), _signed(false), _gradeSign(1), _gradeExec(1){}

Form::Form(const std::string name, const int gradeSign, const int gradeExec): _name(name),  _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec){
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GardeTooLowExeption();
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GardeTooHighExeption();
}

Form::Form(const Form &copy): _name(copy._name), _signed(false), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec){
    if (copy.getSignGrade() > 150 || copy.getExecGrade() > 150)
        throw GardeTooLowExeption();
    if (copy.getSignGrade() < 1 || copy.getExecGrade() < 1)
        throw GardeTooHighExeption();
}

Form    &Form::operator=(Form const &copy){
    if (&copy != this){
        _signed = copy._signed;   
    }
    return *this;
}

Form::~Form(){}

std::string   Form::getName()const{
    return (this->_name);
}

int   Form::getSignGrade()const{
    return (this->_gradeSign);
}

int   Form::getExecGrade()const{
    return (this->_gradeExec);
}

std::string Form::getSignStatus()const{
    if (this->_signed)
        return ("true");
    else
        return ("false");
}

const char* Form::GardeTooHighExeption::what() const throw(){
    return ("Form grade is too high");
}

const char* Form::GardeTooLowExeption::what() const throw(){
    return ("Form grade is too low");
}

const char* Form::FormWasAlreadySigned::what() const throw(){
    return ("This form was already signed");
}

void    Form::beSigned(Bureaucrat &b){
    if (!this->_signed){
        if (b.getGrade() <= this->getSignGrade()){
            this->_signed = true;
            std::cout << b.getName() << " signed form " << this->getName() << "." <<std::endl;
        }
        else{            
            throw Bureaucrat::GradeTooLowException();
        }
    }
    else
        throw FormWasAlreadySigned();
}

std::ostream &operator<<(std::ostream &out, const Form &form){
    out << form.getName() << ", grade to sign " << form.getSignGrade() << ", grade to execute " << form.getExecGrade() << " and its signed status is " << form.getSignStatus() << ".";
    return (out);
}

