#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{ }

HumanB::HumanB(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon)
{ }

HumanB::~HumanB()
{ }

void HumanB::attack() const
{
	if (_weapon == NULL)
		std::cout << _name << " has no weapon" << std::endl;
	else
		std::cout << _name << " attacks with thier " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}