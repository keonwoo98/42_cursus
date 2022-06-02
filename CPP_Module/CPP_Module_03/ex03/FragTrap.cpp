#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap Default constructor : " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap String constructor : " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& frag) : ClapTrap(frag)
{
	std::cout << "FragTrap Copy constructor : " << _name << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor : " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& frag)
{
	ClapTrap::operator=(frag);
	std::cout << "FragTrap Copy assignment operator : " << _name << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (_hp > 0 && _ep > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target \
			<< ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
		std::cout << "FragTrap " << _name << "'s remaining energy point : " << _ep << std::endl;
	}
	else if (_hp <= 0)
		std::cout << "FragTrap " << _name << " already dead" << std::endl;
	else
		std::cout << "FragTrap " << _name << " has no energy point remainding!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
	if (_hp <= amount)
	{
		_hp = 0;
		std::cout << "FragTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
		std::cout << "FragTrap " << _name << " died!" << std::endl;
	}
	else
	{
		_hp -= amount;
		std::cout << "FragTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_hp > 0 && _ep > 0)
	{
		_hp += amount;
		_ep--;
		std::cout << "FragTrap " << _name << " has been repaired of " << amount << " hit point!" << std::endl;
		std::cout << "FragTrap " << _name << "'s remaining hit point : " << _hp << std::endl;
		std::cout << "FragTrap " << _name << "'s remaining energy point : " << _ep << std::endl;
	}
	else if (_hp <= 0)
		std::cout << "FragTrap " << _name << " already dead!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " has no energy point remainding!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " positive high fives request!" << std::endl;
}
