/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:36:00 by pablo             #+#    #+#             */
/*   Updated: 2025/08/28 11:16:04 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include "../includes/General.hpp"
#include "../includes/Contact.hpp"

int execute_input(std::string input,Phonebook& Contact_list)
{
    if(input == "EXIT")
    {
        std::cout<<"bye bye :)"<<std::endl;   
        exit(0);
    }
    else if (input == "ADD")
    {
        if(Contact_list.add_Contact() == -1)
            return(-1);
    }
    else if (input == "SEARCH")
    {
        if(Contact_list.search_contact() == -1)
            return(-1);
    }
    return(0);  
}