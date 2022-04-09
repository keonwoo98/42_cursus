/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:10:29 by keokim            #+#    #+#             */
/*   Updated: 2022/04/08 19:28:29 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	Phonebook book;
	std::string cmd;

	std::cout << "-----Welcome to Awesome PhoneBook!!!-----\n" << std::endl;
	while (1)
	{
		std::cout << "Choose an option (ADD, SEARCH, EXIT): ";
		std::cin >> cmd;
		std::cout << std::endl;
		if (cmd == "ADD")
			book.AddContact();
		else if (cmd == "SEARCH")
			book.ShowContact();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid Command!!" << std::endl;
	}
	return (0);
}
