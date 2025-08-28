/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:19:00 by pablo             #+#    #+#             */
/*   Updated: 2025/08/28 11:13:37 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include<iostream>
# include<string>
# include"../includes/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class Phonebook
{
private:
    Contact contact_list[8];
    int current;
    int total_contacts;
public:
    Phonebook();
    ~Phonebook();
    int add_Contact();
    int search_contact();
    std::string trim(std::string input);
    void truncate_string(std::string);
    int input_error(int flag);
    int analize_input(std::string input);
    std::string trim_and_print(const std::string& prompt);
    void print_contacts();
    int print_a_contact();
};
#endif 
