#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value)
{
	_value = value << _bits;
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value)
{
	_value = round(value * (1 << _bits));
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& cp)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}
Fixed& Fixed::operator=(const Fixed& cp)
{
	std::cout << "Copy assignation operator called" << std::endl;
	if (this != &cp)
		_value = cp._value;
	return *this;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}
int Fixed::toInt(void) const
{
	return (_value >> _bits);
}
float Fixed::toFloat(void) const
{
	return (float(_value) / (1 << _bits));
}
std::ostream& operator<<(std::ostream& os, const Fixed& cp)
{
	os << cp.toFloat();
	return os;
}
