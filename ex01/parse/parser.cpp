/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:45:34 by pablo             #+#    #+#             */
/*   Updated: 2025/08/25 13:22:23 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/General.hpp"


std::string trim(std::string input)
{
   size_t start = 0;
   while (start < input.length() && std::isspace((unsigned char)input[start]))
   {
        start++;
   }
   size_t end = input.length();
   while (end > start && std::isspace((unsigned char)input[end -1]))
   {
        end--;
   }
   return(input.substr(start,end - start));
   
    
}

int analize_input(std::string input)
{
    if(input.empty())
        return(EMPTY);
    if(input == "SEARCH" || input == "ADD" || input == "EXIT")
    {
    
        std::cout << "[" << input << "]" << std::endl;
        return(SUCCESS);
    }
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

