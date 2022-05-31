#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap def;
	ScavTrap r1("Robot1");
	ScavTrap r2("Robot2");

	std::cout << std::endl;
	r1.attack("Robot2");
	r2.takeDamage(r1.getAd());
	std::cout << std::endl;
	
	r2.attack("Default");
	def.takeDamage(r2.getAd());
	std::cout << std::endl;

	def.beRepaired(10);
	std::cout << std::endl;
	
	def.attack("Robot2");
	r2.takeDamage(def.getAd());
	std::cout << std::endl;

	def.guardGate();
	std::cout << std::endl;

	r1.guardGate();
	std::cout << std::endl;

	r2.guardGate();
	std::cout << std::endl;
	
	return 0;
}
