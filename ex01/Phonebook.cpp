/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:12:24 by pablo             #+#    #+#             */
/*   Updated: 2025/08/07 21:14:00 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "General.hpp"
#include "Contact.hpp"

std::string trim(std::string input)
{
   size_t start = 0;
   while (start < input.length() && std::isspace(input[start]))
   {
        start++;
   }
   size_t end = input.length();
   while (end > start && std::isspace(input[end -1]))
   {
        end--;
   }
   return(input.substr(start,end - start));
   
    
}

int analize_input(std::string input)
{
    std::string new_input = trim(input);
   // std::cout << new_input;
    if(new_input.empty())
        return(EMPTY);
    if(new_input == "SEARCH" || new_input == "ADD" || new_input == "EXIT")
        return(SUCCESS);
    return(INVALID);
    
}
int execute_input(std::string input)
{
    if(input == "EXIT")
    {
        std::cout<<"bye bye :)"<<std::endl;   
        exit(0);
    }
    else if (input == "ADD")
    {
        std::cout<< "ejecutando add" << std::endl;
        return(0);
    }
    else if (input == "SEARCH")
    {
        std::cout<< "ejecutando search" << std::endl;
        return(0);
    }
    return(0);
    
    
}
int input_error(int flag)
{
    if(flag == EMPTY)
        std::cout << "empty input please insert input" << std::endl;
    else if (flag == INVALID)
        std::cout << "invalid input please insert correct input" << std::endl;
    return(0);
}

int main(void)
{
    std::string input;
    int flag;
    while (true)
    {
        std::cout<<"input comand -> ";
        std::getline(std::cin,input);
        flag = analize_input(input);
        if (flag == SUCCESS)
            execute_input(input);
        else
            input_error(flag);
            
    }
    
    return(0);
}