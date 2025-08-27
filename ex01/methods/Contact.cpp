/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:25:26 by pablo             #+#    #+#             */
/*   Updated: 2025/08/27 12:22:57 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

bool Contact::ValidContact()  const
{
    return !(Name.empty() 
        || Last_Name.empty() 
        || nick_name.empty() 
        || telf_number.empty() 
        || dark_secret.empty()); 
}