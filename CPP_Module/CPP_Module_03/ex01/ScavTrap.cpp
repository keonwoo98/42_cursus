#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap Default constructor : " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap String constructor : " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scav) : ClapTrap(scav)
{
	std::cout << "ScavTrap Copy constructor : " << _name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor : " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scav)
{
	ClapTrap::operator=(scav);
	std::cout << "ScavTrap Copy assignment operator : " << _name << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hp > 0 && _ep > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target \
			<< ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
		std::cout << "ScavTrap " << _name << "'s remaining energy point : " << _ep << std::endl;
	}
	else if (_hp <= 0)
		std::cout << "ScavTrap " << _name << " already dead" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " has no energy point remainding!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
	if (_hp <= amount)
	{
		_hp = 0;
		std::cout << "ScavTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
		std::cout << "ScavTrap " << _name << " died!" << std::endl;
	}
	else
	{
		_hp -= amount;
		std::cout << "ScavTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hp > 0 && _ep > 0)
	{
		_hp += amount;
		_ep--;
		std::cout << "ScavTrap " << _name << " has been repaired of " << amount << " hit point!" << std::endl;
		std::cout << "ScavTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
		std::cout << "ScavTrap " << _name << "'s remaining energy point : " << _ep << std::endl;
	}
	else if (_hp <= 0)
		std::cout << "ScavTrap " << _name << " already dead!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " has no energy point remainding!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_hp > 0)
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " cannot enter Gate keeper mode because " << _name << " is dead!" << std::endl;
}
