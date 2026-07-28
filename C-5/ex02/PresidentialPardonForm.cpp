/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:07:55 by antabord          #+#    #+#             */
/*   Updated: 2026/05/27 13:23:54 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5),_target(target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
    if (this != &copy)
        _target = copy._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):AForm("PresidentialPardonForm", copy.getSignGrade(), copy.getExecGrade()){
    *this = copy;
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor)const{
    if (!getSignStatus())
        throw AForm::AFormWasNotSignedYet();
    if (executor.getGrade() >= getSignGrade())
        throw AForm::InvalidSignGrade();
    if (executor.getGrade() >= getExecGrade())
        throw AForm::InvalidExecGrade();
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}