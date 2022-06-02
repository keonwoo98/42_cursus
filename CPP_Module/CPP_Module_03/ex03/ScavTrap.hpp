#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public :
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& scav);
	~ScavTrap(void);
	ScavTrap& operator=(const ScavTrap& scav);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate(void);
};

#endif
