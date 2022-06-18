#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat& c) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = c.getType();
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& c)
{
	std::cout << "Cat copy assignation operator called" << std::endl;
	_type = c.getType();
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat Sound : Meow~ Meow~" << std::endl;
}
