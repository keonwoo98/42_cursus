#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
private :
	std::string _name;
	std::string _title;

	Warlock(void);
	Warlock(const Warlock& w);
	Warlock& operator=(const Warlock& w);

public :
	Warlock(std::string name, std::string title);
	~Warlock(void);

	std::string getName(void) const;
	std::string getTitle(void) const;
	
	void setTitle(std::string title);
	void introduce(void) const;
};

#endif
