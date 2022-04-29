#include "Zombie.hpp"

int main()
{
	Zombie* family = zombieHorde(5, "family");

	for (int i = 0; i < 5; i++)
		family->announce();
	delete []family;
}
