/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:04 by pablo             #+#    #+#             */
/*   Updated: 2025/08/28 11:15:02 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/Phonebook.hpp"
#include"includes/General.hpp"
#include"includes/Contact.hpp"

int main(void)
{
    std::string input;
    Phonebook phonebook;
    int flag;
    while (true)
    {
        std::cout<<"input comand -> ";
        std::getline(std::cin,input);
        if(std::cin.eof())
            exit(1);
        input = phonebook.trim(input);
        flag = analize_input(input);
        if (flag == SUCCESS)
        {
            if(execute_input(input,phonebook) == -1)
                break;
        }
        else
            input_error(flag); 
    } 
    return(0);
}