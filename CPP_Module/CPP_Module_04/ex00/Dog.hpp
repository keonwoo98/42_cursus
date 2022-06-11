#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public :
	Dog(void);
	Dog(const Dog& d);
	virtual ~Dog(void);
	Dog& operator=(const Dog& d);

	void makeSound(void) const;
};

#endif
