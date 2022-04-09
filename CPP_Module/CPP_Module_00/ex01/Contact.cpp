/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:02:17 by keokim            #+#    #+#             */
/*   Updated: 2022/04/08 19:57:41 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::GetContactInfo()
{
	std::cout << "Please insert contact info..." << std::endl;
	std::cout << "First Name : ";
	std::cin >> first_name;
	std::cout << "Last Name : ";
	std::cin >> last_name;
	std::cout << "Nickname : ";
	std::cin >> nickname;
	std::cout << "Phone Number : ";
	std::cin >> phone_number;
	std::cout << "Darkest Secret : ";
	std::cin >> darkest_secret;
	std::cout << std::endl;
}

void Contact::SearchContact(int idx)
{
	std::cout << std::setw(10) << "Contact : " << idx << std::endl;
	std::cout << std::setw(10) << "First Name : " << first_name << std::endl;
	std::cout << std::setw(10) << "Last Name : " << last_name << std::endl;
	std::cout << std::setw(10) << "Nickname : " << nickname << std::endl;
	std::cout << std::setw(10) << "Phone Number : " << phone_number << std::endl;
	std::cout << std::setw(10) << "Darkest Secret : " << darkest_secret << std::endl;
	std::cout << std::endl;
}

std::string Contact::GetName()
{
	return (first_name);
}

std::string Contact::GetLastName()
{
	return (last_name);
}

std::string Contact::GetNickname()
{
	return (nickname);
}

std::string Contact::GetPhoneNum()
{
	return (phone_number);
}
