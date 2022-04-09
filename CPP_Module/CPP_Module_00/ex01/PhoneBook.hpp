/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:32:11 by keokim            #+#    #+#             */
/*   Updated: 2022/04/08 23:14:51 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
private :
    Contact contacts[8];
    int index;
    int findex;
    int empty;
    int full;
public :
    Phonebook();
    void PrintPhonebook();
    void PrintContact(int i, int idx);
    void AddContact();
    void ShowContact();
};

#endif
