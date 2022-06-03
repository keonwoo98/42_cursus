#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private :
	std::string _name;
public :
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& diamond);
	~DiamondTrap(void);
	DiamondTrap& operator=(const DiamondTrap& diamond);

	void attack(const std::string& target);
	void whoAmI(void) const;
};

#endif
