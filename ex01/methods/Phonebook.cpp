/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:12:24 by pablo             #+#    #+#             */
/*   Updated: 2025/08/27 18:03:28 by pablo            ###   ########.fr       */
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
   while (end > start && std::isspace((unsigned char)input[end - 1]))
        end--;
   return(input.substr(start,end - start));  
}
void Phonebook::truncate_string(std::string prompt)
{
    if(prompt.length() > 10)
        std::cout << std::setw(10) << std::right, std::cout << prompt.substr(0,9)+"." , std::cout << "|";
    else
        std::cout << std::setw(10) << std::right, std::cout << prompt, std::cout << "|";
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
    temp_contact.name = Phonebook::trim_and_print("insert contact name -> ");
    temp_contact.last_Name = Phonebook::trim_and_print("insert last name -> ");
    temp_contact.nick_name = Phonebook::trim_and_print("insert nick name -> ");
    temp_contact.telf_number = Phonebook::trim_and_print("insert telephone number -> ");
    temp_contact.dark_secret = Phonebook::trim_and_print("insert darkest secret -> ");
    if(!temp_contact.valid_contact())
        return(void)(std::cout << "Invalid parameters please try again.", std::cout << std::endl);
    contact_list[current] = temp_contact;
    std::cout << "contact added succesfully :)", std::cout << std::endl;
    current = (current + 1) % 8;
    if(total_contacts < 8)
        total_contacts++;
}
void Phonebook::print_contacts()
{
    Phonebook::truncate_string("INDEX");
    Phonebook::truncate_string("NAME");
    Phonebook::truncate_string("LAST NAME");
    Phonebook::truncate_string("NICK NAME");
    std::cout << std::endl;
    for (int i = 0; i < total_contacts; i++)
    {
        std::cout << std::setw(10) << std::right, std::cout << i , std::cout << "|";
        Phonebook::truncate_string(contact_list[i].name);
        Phonebook::truncate_string(contact_list[i].last_Name);
        Phonebook::truncate_string(contact_list[i].nick_name);
        std::cout << std::endl;     
    }
}
void Phonebook::print_a_contact()
{
    int to_print;
    std::string input;
    std::getline(std::cin,input);
    std::istringstream iss(input);
    iss >> to_print;
    if(to_print > Phonebook::total_contacts)
    {
        std::cout << "invalid index put anotherone -> ";
        Phonebook::print_a_contact();
    }
    else
    {
        std::cout << "Index -> " << to_print << std::endl;
        std::cout << "Name -> " << contact_list[to_print].name << std::endl;
        std::cout << "Last Name -> " << contact_list[to_print].last_Name << std::endl;
        std::cout << "Nick Name -> " << contact_list[to_print].nick_name << std::endl;
        std::cout << "Telephone Number -> " << contact_list[to_print].telf_number << std::endl;
        std::cout << "Darkest Secret -> " << contact_list[to_print].dark_secret << std::endl;
    }
    
}
void Phonebook::search_contact()
{
    
    if (total_contacts == 0)
    {
        std::cout << "No contacts added to list" << std::endl;
        return;
    }
    Phonebook::print_contacts();
    std::cout << "please insert desired index -> ";
    Phonebook::print_a_contact();
}

