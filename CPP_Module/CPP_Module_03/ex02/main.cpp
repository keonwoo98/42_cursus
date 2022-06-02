#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap def;
	ScavTrap s1("Scav1");
	FragTrap f1("Frag1");

	std::cout << std::endl;
	s1.attack("Frag1");
	f1.takeDamage(s1.getAd());
	std::cout << std::endl;
	
	f1.attack("Default");
	def.takeDamage(f1.getAd());
	std::cout << std::endl;

	def.beRepaired(100);
	std::cout << std::endl;

	s1.guardGate();
	std::cout << std::endl;

	f1.highFivesGuys();
	std::cout << std::endl;
	
	return 0;
}
