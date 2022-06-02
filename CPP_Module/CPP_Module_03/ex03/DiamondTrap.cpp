#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(), _name(ClapTrap::_name)
{
	ClapTrap::_name += "_clap_name";
	_ep = 50;
	std::cout << "DiamondTrap Default constructor : " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_ep = 50;
	std::cout << "DiamondTrap String constructor : " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamond) : ClapTrap(diamond), ScavTrap(diamond), FragTrap(diamond), _name(diamond._name)
{
	std::cout << "DiamondTrap Copy constructor : " << _name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor : " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamond)
{
	ClapTrap::operator=(diamond);
	std::cout << "DiamondTrap Copy assignment operator : " << _name << std::endl;
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	// if (_hp > 0 && _ep > 0)
	// {
	// 	std::cout << "DiamondTrap " << _name << " attacks " << target \
	// 		<< ", causing " << _ad << " points of damage!" << std::endl;
	// 	_ep--;
	// 	std::cout << "DiamondTrap " << _name << "'s remaining energy point : " << _ep << std::endl;
	// }
	// else if (_hp <= 0)
	// 	std::cout << "DiamondTrap " << _name << " already dead" << std::endl;
	// else
	// 	std::cout << "DiamondTrap " << _name << " has no energy point remainding!" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << "DiamondTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
	if (_hp <= amount)
	{
		_hp = 0;
		std::cout << "DiamondTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
		std::cout << "DiamondTrap " << _name << " died!" << std::endl;
	}
	else
	{
		_hp -= amount;
		std::cout << "DiamondTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
	}
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (_hp > 0 && _ep > 0)
	{
		_hp += amount;
		_ep--;
		std::cout << "DiamondTrap " << _name << " has been repaired of " << amount << " hit point!" << std::endl;
		std::cout << "DiamondTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
		std::cout << "DiamondTrap " << _name << "'s remaining energy point : " << _ep << std::endl;
	}
	else if (_hp <= 0)
		std::cout << "DiamondTrap " << _name << " already dead!" << std::endl;
	else
		std::cout << "DiamondTrap " << _name << " has no energy point remainding!" << std::endl;
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "Who am I?" << std::endl;
	std::cout << "DiamondTrap name : " << _name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl;
}
