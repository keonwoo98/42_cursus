#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie zzz = Zombie(name);

	zzz.announce();
}
