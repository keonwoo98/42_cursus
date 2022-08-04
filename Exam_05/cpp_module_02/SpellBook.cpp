#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::SpellBook(const SpellBook& s) : _book(s._book) {}

SpellBook& SpellBook::operator=(const SpellBook& s)
{
	_book = s._book;
	return *this;
}

SpellBook::~SpellBook(void) {}

void SpellBook::learnSpell(ASpell* spell)
{
	_book.insert(std::make_pair(spell->getName(), spell));
}

void SpellBook::forgetSpell(const std::string& name)
{
	_book.erase(name);
}

ASpell* SpellBook::createSpell(const std::string& name)
{
	std::map<std::string, ASpell*>::iterator it;

	it = _book.find(name);
	if (it != _book.end())
		return it->second;
	return NULL;
}
