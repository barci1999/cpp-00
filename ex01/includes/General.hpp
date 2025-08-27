/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   General.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:18:28 by pablo             #+#    #+#             */
/*   Updated: 2025/08/25 14:42:49 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_HPP
# define GENERAL_HPP
# include<iostream>
# include<string>
# include <cstdlib>
#include "../includes/Phonebook.hpp"
enum
{
    SUCCESS = 0,
    EMPTY = -1,
    INVALID = -2,
};

int input_error(int flag);
int execute_input(std::string input,Phonebook &contact_list);
int analize_input(std::string input);
std::string trim(std::string input);

#endif