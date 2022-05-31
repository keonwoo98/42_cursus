#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap def;
	ScavTrap r1("Robot1");
	FragTrap r2("Robot2");

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

	r1.guardGate();
	std::cout << std::endl;

	r2.highFivesGuys();
	std::cout << std::endl;
	
	return 0;
}
