/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:18:20 by keokim            #+#    #+#             */
/*   Updated: 2022/04/09 16:26:47 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	index = 0;
	findex = 0;
	empty = 1;
	full = 0;
}

void Phonebook::AddContact()
{
	if (index == 8)
		index = 0;
	contacts[index].GetContactInfo();
	index++;
	findex++;
	if (empty)
		empty = 0;
	if (!full && index == 8)
		full = 1;
}

void Phonebook::PrintPhonebook()
{
	std::cout << std::setw(10) << "Index" << '|';
	std::cout << std::setw(10) << "Name" << '|';
	std::cout << std::setw(10) << "Last Name" << '|';
	std::cout << std::setw(10) << "Nickname" << '|' << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void Phonebook::PrintContact(int i, int idx)
{
	std::cout << std::setw(10) << idx << '|';
	std::cout << std::setw(10) << contacts[i].GetName() << '|';
	std::cout << std::setw(10) << contacts[i].GetLastName() << '|';
	std::cout << std::setw(10) << contacts[i].GetNickname() << '|' << std::endl;
}

void Phonebook::ShowContact()
{
	int i;
	int select;

	PrintPhonebook();
	if (full)
	{
		index == 8 ? i = 0 : i = index;
		for (int j = 0; j < 8; j++)
		{
			if (i == 8)
				i = 0;
			PrintContact(i, j + 1);
			i++;
		}
	}
	else
	{
		for (i = 0; i < index; i++)
			PrintContact(i, i + 1);
	}
	std::cout << std::endl << std::endl;
	std::cout << "Select a contact for detail info : ";
	std::cin >> select;
	std::cout << std::endl;
	if (empty)
	{
		std::cout << "PhoneBook is empty!!\n" << std::endl;
		return ;
	}
	else
	{
		select--;
		if (full)
		{
			while (select <= findex)
				select += 8;
			select -= 8;
			contacts[select % 8 + 1].SearchContact(select % 8 + 1);
		}
		else
			contacts[select].SearchContact(select + 1);
	}
}
