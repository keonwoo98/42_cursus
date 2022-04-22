#ifndef TABLE_HPP
# define TABLE_HPP

#include "Contact.hpp"

class Table
{
private :
	std::string TruncateContact(std::string info);

public :
	void PrintTable(Contact contacts[8]);
	void PrintContact(Contact contacts[8], int select);
};

#endif
