#include "ATarget.hpp"

ATarget::ATarget(void) {}

ATarget::ATarget(std::string type) : _type(type) {}

ATarget::ATarget(const ATarget& a) : _type(a.getType()) {}

ATarget::~ATarget(void) {}

ATarget& ATarget::operator=(const ATarget& a)
{
	_type = a.getType();
	return *this;
}

std::string ATarget::getType(void) const
{
	return _type;
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
