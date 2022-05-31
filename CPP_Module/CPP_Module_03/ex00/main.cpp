#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap def;
	ClapTrap r1("Robot1");
	ClapTrap r2("Robot2");

	std::cout << std::endl;
	r1.attack("Robot2");
	r2.takeDamage(5);
	std::cout << std::endl;
	
	r2.attack("Default");
	def.takeDamage(5);
	std::cout << std::endl;

	def.beRepaired(10);
	std::cout << std::endl;
	
	def.attack("Robot2");
	r2.takeDamage(5);
	std::cout << std::endl;
	
	return 0;
}
