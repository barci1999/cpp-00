/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:12:24 by pablo             #+#    #+#             */
/*   Updated: 2025/08/27 13:17:54 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include "../includes/General.hpp"
#include "../includes/Contact.hpp"

Phonebook::Phonebook()
{
    Phonebook::current = 0;
    Phonebook::total_contacts = 0;
}
Phonebook::~Phonebook()
{
    return;
}
std::string Phonebook::trim(std::string input)
{
   size_t start = 0;
   while (start < input.length() && std::isspace((unsigned char)input[start]))
        start++;
   size_t end = input.length();
   while (end > start && std::isspace((unsigned char)input[end -1]))
        end--;
   return(input.substr(start,end - start));  
}

std::string Phonebook::trim_and_print(const std::string& prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    input = trim(input); 
    return (input);
}
int analize_input(std::string input)
{
    if(input.empty())
        return(EMPTY);
    if(input == "SEARCH" || input == "ADD" || input == "EXIT")
        return(SUCCESS);
    return(INVALID);
    
}
int input_error(int flag)
{
    if(flag == EMPTY)
        std::cout << "empty input please insert input" << std::endl;
    else if (flag == INVALID)
        std::cout << "invalid input please insert correct input" << std::endl;
    return(0);
}
void Phonebook::add_Contact()
{
    Contact temp_contact;
    if(current == 8)
        current = 0;
    temp_contact.Name = Phonebook::trim_and_print("insert contact name -> ");
    temp_contact.Last_Name = Phonebook::trim_and_print("insert last name -> ");
    temp_contact.nick_name = Phonebook::trim_and_print("insert nick name -> ");
    temp_contact.telf_number = Phonebook::trim_and_print("insert telephone number -> ");
    temp_contact.dark_secret = Phonebook::trim_and_print("insert darkest secret -> ");
    if(!temp_contact.ValidContact())
        return(void)(std::cout << "Invalid parameters please try again.", std::cout << std::endl);
    contact_list[current] = temp_contact;
    std::cout << "contact added succesfully :)", std::cout << std::endl;
    current = (current + 1) % 8;
    if(total_contacts < 8)
        total_contacts++;
}

