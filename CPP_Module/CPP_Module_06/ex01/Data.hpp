#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
private :
	std::string _name;
	int _age;
	float _height;
public :
	Data(void);
	Data(std::string name, int age, float height);
	Data(const Data& d);
	~Data(void);
	Data& operator=(const Data& d);

	const std::string getName() const;
	int getAge() const;
	float getHeight() const;
	void print(void) const;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
