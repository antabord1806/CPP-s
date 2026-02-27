/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:00:56 by antabord          #+#    #+#             */
/*   Updated: 2026/02/26 18:00:57 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contacts::Contacts(){
}

Contacts::~Contacts(){
}

void Contacts::updateContact(){
    std::string line;
    std::cout << "Firstname:" << std::endl;
    std::getline(std::cin, line);
    this->firstname = line;
    std::cout << "Number:" << std::endl;
    std::getline(std::cin, line);
    this->number = line;
    std::cout << "Lastname:" << std::endl;
    std::getline(std::cin, line);
    this->lastname = line;
    std::cout << "Nickname:" << std::endl;
    std::getline(std::cin, line);
    this->nickname = line;
    std::cout << "Darksecret:" << std::endl;
    this->darksecret = line;
}

std::string Contacts::getfirstname(){
    if (this->firstname.length() > 9)
    {
        std::string sub;
        sub = this->firstname.substr(0, 9) + ".";
        return (sub);
    }
    else
        return (this->firstname);
}

std::string Contacts::getlastname(){
    if (this->lastname.length() > 9)
    {
        std::string sub;
        sub = this->lastname.substr(0, 9) + ".";
        return (sub);
    }
    else
        return (this->lastname);
}

std::string Contacts::getnickname(){
    if (this->nickname.length() > 9)
    {
        std::string sub;
        sub = this->nickname.substr(0, 9) + ".";
        return (sub);
    }
    else
        return (this->nickname);
}