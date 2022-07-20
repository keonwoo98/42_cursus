#ifndef ASPELL_HPP
#define ASPELL_HPP

#include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
	std::string _name;
	std::string _effects;

public:
	ASpell(void);
	ASpell(std::string name, std::string effects);
	ASpell(const ASpell &a);
	virtual ~ASpell(void);
	ASpell& operator=(const ASpell &a);

	std::string getName(void) const;
	std::string getEffects(void) const;

	void launch(const ATarget &target);
	virtual ASpell* clone(void) const = 0;
};

#endif
