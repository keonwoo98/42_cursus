#include "PhoneBook.hpp"

int main()
{
	int contacts;
	Phonebook book;
	std::string cmd;

	contacts = 0;
	std::cout << "-----Welcome to Awesome PhoneBook!!!-----\n" << std::endl;
	while (1)
	{
		std::cout << "Choose an option (ADD, SEARCH, EXIT): ";
		std::cin >> cmd;
		if (std::cin.eof())
			break ;
		std::cout << std::endl;
		if (cmd == "ADD")
		{
			book.AddContact(contacts);
			contacts++;
			if (contacts == 8)
				contacts = 0;
		}
		else if (cmd == "SEARCH")
			book.SearchContact();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid Command!!" << std::endl;
	}
	return (0);
}
