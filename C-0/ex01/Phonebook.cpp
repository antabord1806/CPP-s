/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:01:07 by antabord          #+#    #+#             */
/*   Updated: 2026/02/26 18:01:08 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(): contacts(), max(8) , count(0)
{
    std::cout << "Phonebook construido" << std::endl;
}

Phonebook::~Phonebook(){
    std::cout << "Phonebook destruido" << std::endl;
}

void Phonebook::addContact(void){
    static int maxedout = 0;
    if (count == max)
    {
        this->contacts[maxedout].updateContact();
        maxedout++;
        if (maxedout == 8)
            maxedout = 0;
    }
    else
    {
        this->contacts[count].updateContact();
        count++;
    }
}


void Phonebook::searchContact(void){
    int display_index = 1;
    int index = 0;
    std::cout << "All contacts:" << std::endl;
    while (index < 8 && display_index < 9)
    {
        std::string line;
        std::cout << std::setw(10) << display_index << "|";
        std::cout << std::setw(10) << contacts[index].getfirstname() << "|";
        std::cout << std::setw(10) << contacts[index].getlastname() << "|";
        std::cout << std::setw(10) << contacts[index].getnickname() << "|";
        std::cout << std::endl;
        index++;
        display_index++;
    }
}

