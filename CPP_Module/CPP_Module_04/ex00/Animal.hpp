#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected :
	std::string _type;
public :
	Animal(void);
	Animal(const Animal& a);
	virtual ~Animal(void);
	Animal& operator=(const Animal& a);

	void setType(const std::string& type);
	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif
