#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d1("Diamond1");
	DiamondTrap d2("Diamond2");
	DiamondTrap d3("Diamond3");

	std::cout << std::endl;
	d1.whoAmI();
	std::cout << std::endl;

	d2.whoAmI();
	d3.whoAmI();
	d3.highFivesGuys();
	std::cout << std::endl;

	d2.attack("Diamond3");
	d3.takeDamage(d2.getAd());
	std::cout << std::endl;

	d2.guardGate();
	
	return 0;
}
