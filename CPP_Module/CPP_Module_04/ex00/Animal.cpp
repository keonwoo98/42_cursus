#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const Animal& a) : _type(a._type)
{
	std::cout << "Copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
	std::cout << "Copy assignation operator called" << std::endl;
	_type = a.getType();
	return *this;
}

void Animal::setType(const std::string& type)
{
	_type = type;
}

std::string Animal::getType(void) const
{
	return _type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal Sound : ?" << std::endl;
}
