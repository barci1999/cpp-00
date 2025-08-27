/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:12:58 by pablo             #+#    #+#             */
/*   Updated: 2025/08/27 12:54:47 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include<iostream>
# include<string>

class Contact
{
public:
    std::string Name;
    std::string Last_Name;
    std::string nick_name;
    std::string telf_number;
    std::string dark_secret;
    bool ValidContact() const;
};

#endif