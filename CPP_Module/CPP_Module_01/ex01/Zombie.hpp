#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private :
	std::string _name;

public :
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce() const;
	void setname(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
