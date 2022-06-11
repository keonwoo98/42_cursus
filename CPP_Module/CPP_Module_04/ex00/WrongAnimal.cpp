#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wa) : _type(wa._type)
{
	std::cout << "Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wa)
{
	std::cout << "Copy assignation operator called" << std::endl;
	_type = wa.getType();
	return *this;
}

void WrongAnimal::setType(const std::string& type)
{
	_type = type;
}

std::string WrongAnimal::getType(void) const
{
	return _type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Animal Sound : ?" << std::endl;
}
