/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:04 by pablo             #+#    #+#             */
/*   Updated: 2025/08/25 12:51:55 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/Phonebook.hpp"
#include"includes/General.hpp"
#include"includes/Contact.hpp"

int main(void)
{
    std::string input;
    int flag;
    while (true)
    {
        std::cout<<"input comand -> ";
        std::getline(std::cin,input);
        input = trim(input);
        flag = analize_input(input);
        if (flag == SUCCESS)
            execute_input(input);
        else
            input_error(flag);
            
    } 
    return(0);
}