/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:07:55 by antabord          #+#    #+#             */
/*   Updated: 2026/05/27 14:10:25 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShruberryCreationForm", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShruberryCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm("RobotomyRequestForm", copy.getSignGrade(), copy.getExecGrade()){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
    if (this != &copy)
        _target = copy._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}


void    ShrubberyCreationForm::execute(const Bureaucrat &executor)const{
    if (!getSignStatus())
        throw AForm::AFormWasNotSignedYet();
    if (executor.getGrade() >= getSignGrade())
        throw AForm::InvalidSignGrade();
    if (executor.getGrade() >= getExecGrade())
        throw AForm::InvalidExecGrade();
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    std::string outname = (std::string(_target) + "_shrubbery");
    std::ofstream outfile(outname.c_str());
    if (!outfile.is_open())
        throw std::runtime_error("Error: Cant open output file");
    outfile << "       _-_\n";
    outfile << "    /~~   ~~\\\n";
    outfile << " /~~         ~~\\\n";
    outfile << "{               }\n";
    outfile << " \\  _-     -_  /\n";
    outfile << "   ~  \\\\ //  ~\n";
    outfile << "_- -   | | _- _\n";
    outfile << "  _ -  | |   -_\n";
    outfile << "      // \\\\\n";
    outfile.flush();
    outfile.close();
}