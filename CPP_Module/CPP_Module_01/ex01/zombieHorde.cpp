#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Parameter N is invalid" << std::endl;
		return NULL;
	}
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setname(name);
	return horde;
}
