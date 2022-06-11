#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public :
	Cat(void);
	Cat(const Cat& c);
	virtual ~Cat(void);
	Cat& operator=(const Cat& c);

	void makeSound(void) const;
};

#endif
