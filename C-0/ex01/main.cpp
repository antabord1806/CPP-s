/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:01:02 by antabord          #+#    #+#             */
/*   Updated: 2026/02/26 18:01:03 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook phone;
    while (42)
    {
        std::string line;
        getline(std::cin, line);
        if (line == "add")
            phone.addContact();
        if (line == "search")
            phone.searchContact();
        if (line == "exit")
            break;
    }
}