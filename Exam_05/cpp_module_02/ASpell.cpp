#include "ASpell.hpp"

ASpell::ASpell(void) {}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell &a) : _name(a.getName()), _effects(a.getEffects()) {}

ASpell::~ASpell(void) {}

ASpell& ASpell::operator=(const ASpell &a)
{
	_name = a.getName();
	_effects = a.getEffects();
	return *this;
}

std::string ASpell::getName(void) const
{
	return _name;
}

std::string ASpell::getEffects(void) const
{
	return _effects;
}

void ASpell::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}
