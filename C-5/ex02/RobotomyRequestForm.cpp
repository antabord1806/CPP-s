/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:07:55 by antabord          #+#    #+#             */
/*   Updated: 2026/05/27 13:23:54 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm("RobotomyRequestForm", copy.getSignGrade(), copy.getExecGrade()){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
    if (this != &copy)
        _target = copy._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}


void    RobotomyRequestForm::execute(const Bureaucrat &executor)const{
    if (!getSignStatus())
        throw AForm::AFormWasNotSignedYet();
    if (executor.getGrade() >= getSignGrade())
        throw AForm::InvalidSignGrade();
    if (executor.getGrade() >= getExecGrade())
        throw AForm::InvalidExecGrade();
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    if (!(std::rand() % 2))
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomization of " << _target << " failed" << std::endl;
}