#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d1("Diamond1");
	DiamondTrap d2("Diamond2");
	DiamondTrap d3;

	std::cout << std::endl;
	d1.whoAmI();
	std::cout << std::endl;

	d2.guardGate();
	std::cout << std::endl;

	d3.highFivesGuys();
	std::cout << std::endl;

	d1.attack("Diamond2");
	d2.takeDamage(d1.getAd());
	std::cout << std::endl;

	d2.attack("Diamond3");
	d3.takeDamage(d2.getAd());
	std::cout << std::endl;
	
	return 0;
}
