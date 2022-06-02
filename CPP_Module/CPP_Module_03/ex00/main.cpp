#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap def;
	ClapTrap c1("Clap1");
	ClapTrap c2("Clap2");

	std::cout << std::endl;
	while (c1.is_alive() && c2.is_alive())
	{
		c1.attack("Clap2");
		c2.takeDamage(c1.getAd());
		std::cout << std::endl;
	}
	std::cout << std::endl;
	def.beRepaired(10);
	std::cout << std::endl;
	
	return 0;
}
