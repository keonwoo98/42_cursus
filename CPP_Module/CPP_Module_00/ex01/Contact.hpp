#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Contact
{
private :
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public :
	void GetContactInfo();
	void ShowContact(int idx);
	std::string GetName();
	std::string GetLastName();
	std::string GetNickname();
};

#endif
