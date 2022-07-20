#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>
#include "ASpell.hpp"

class SpellBook
{
private :
	std::map<std::string, ASpell*> _book;

	SpellBook(const SpellBook& s);
	SpellBook& operator=(const SpellBook& s);

public :
	SpellBook(void);
	~SpellBook(void);

	void learnSpell(ASpell* spell);
	void forgetSpell(const std::string& name);
	ASpell* createSpell(const std::string& name);
};

#endif
