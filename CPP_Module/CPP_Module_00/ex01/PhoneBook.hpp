#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Table.hpp"

class Phonebook
{
private:
	Contact contacts[8];

public:
	void AddContact(int index);
	void SearchContact();
};

#endif
