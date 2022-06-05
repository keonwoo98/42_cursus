#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{ }

Zombie::Zombie(std::string name) : _name(name)
{ }

Zombie::~Zombie()
{
	std::cout << _name << " zombie destroyed." << std::endl;
}

void Zombie::announce() const
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
