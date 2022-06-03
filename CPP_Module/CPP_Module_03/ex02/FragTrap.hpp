#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public :
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& frag);
	~FragTrap(void);
	FragTrap& operator=(const FragTrap& frag);

	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif
