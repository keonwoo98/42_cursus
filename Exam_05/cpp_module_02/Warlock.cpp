#include "Warlock.hpp"

Warlock::Warlock(void) {}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
	_book = new SpellBook();
}

Warlock::Warlock(const Warlock& w) : _name(w.getName()), _title(w.getTitle()) {}

Warlock::~Warlock(void)
{
	std::cout << _name << ": My job here is done!" << std::endl;
	delete _book;
}

Warlock& Warlock::operator=(const Warlock& w)
{
	_name = w.getName();
	_title = w.getTitle();
	return *this;
}

std::string Warlock::getName(void) const
{
	return _name;
}

std::string Warlock::getTitle(void) const
{
	return _title;
}

void Warlock::setTitle(std::string title)
{
	_title = title;
}

void Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	_book->learnSpell(spell);
}

void Warlock::forgetSpell(std::string name)
{
	_book->forgetSpell(name);
}

void Warlock::launchSpell(std::string name, ATarget& target)
{
	ASpell *spell = _book->createSpell(name);
	
	if (spell)
		spell->launch(target);
}
