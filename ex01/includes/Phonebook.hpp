/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:19:00 by pablo             #+#    #+#             */
/*   Updated: 2025/08/27 13:18:16 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include<iostream>
# include<string>
# include"../includes/Contact.hpp"

class Phonebook
{
private:
    Contact contact_list[8];
    int current;
    int total_contacts;
public:
    Phonebook();
    ~Phonebook();
    void add_Contact();
    std::string trim(std::string input);
    int input_error(int flag);
    int analize_input(std::string input);
    std::string trim_and_print(const std::string& prompt);
  //  void search_Contact();
//    void take_Exit();

};



#endif 
