/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:53:59 by antabord          #+#    #+#             */
/*   Updated: 2026/05/27 14:06:51 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name(""), _signed(false), _gradeSign(1), _gradeExec(1){}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec): _name(name),  _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec){
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GardeTooLowExeption();
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GardeTooHighExeption();
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(false), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec){
    if (copy.getSignGrade() > 150 || copy.getExecGrade() > 150)
        throw GardeTooLowExeption();
    if (copy.getSignGrade() < 1 || copy.getExecGrade() < 1)
        throw GardeTooHighExeption();
}

AForm    &AForm::operator=(AForm const &copy){
    if (&copy != this){
        _signed = copy._signed;   
    }
    return *this;
}

AForm::~AForm(){}

const std::string   &AForm::getName()const{
    return (this->_name);
}

int   AForm::getSignGrade()const{
    return (this->_gradeSign);
}

int   AForm::getExecGrade()const{
    return (this->_gradeExec);
}

bool AForm::getSignStatus()const{
    return (this->_signed);
}

const char* AForm::GardeTooHighExeption::what() const throw(){
    return ("AForm grade is too high");
}

const char* AForm::GardeTooLowExeption::what() const throw(){
    return ("AForm grade is too low");
}

const char* AForm::AFormWasNotSignedYet::what() const throw(){
    return ("This AForm was already signed");
}

const char* AForm::AFormWasAlreadySigned::what() const throw(){
    return ("This AForm was already signed");
}

const char* AForm::InvalidSignGrade::what() const throw(){
    return ("Invalid sign garde");
}

const char* AForm::InvalidExecGrade::what() const throw(){
    return ("Invalid exec grade");
}


void    AForm::beSigned(Bureaucrat &b){
    if (!getSignStatus()){
        if (b.getGrade() <= this->getSignGrade()){
            this->_signed = true;
        }
        else{
            throw Bureaucrat::GradeTooLowException();
        }
    }
    else
        throw AFormWasAlreadySigned();
}


std::ostream &operator<<(std::ostream &out, const AForm &AForm){
    out << AForm.getName() << ", grade to sign " << AForm.getSignGrade() << ", grade to execute " << AForm.getExecGrade() << " and its signed status is " << AForm.getSignStatus() << ".";
    return (out);
}

