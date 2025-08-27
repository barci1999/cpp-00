/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:25:26 by pablo             #+#    #+#             */
/*   Updated: 2025/08/27 16:19:20 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

bool Contact::valid_contact()  const
{
    return !(name.empty() 
        || last_Name.empty() 
        || nick_name.empty() 
        || telf_number.empty() 
        || dark_secret.empty()); 
}