#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
private :
	std::string _type;

public :
	ATarget(void);
	ATarget(std::string type);
	ATarget(const ATarget& a);
	virtual ~ATarget(void);
	ATarget& operator=(const ATarget& a);

	std::string getType(void) const;

	void getHitBySpell(const ASpell& spell) const;
	virtual ATarget* clone(void) const = 0;
};

#endif
