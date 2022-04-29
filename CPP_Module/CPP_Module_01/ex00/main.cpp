#include "Zombie.hpp"

int main()
{
	Zombie dad = Zombie("Daddy");
	Zombie* mom = newZombie("Mommy");

	dad.announce();
	mom->announce();
	randomChump("Brother");

	delete mom;
}
