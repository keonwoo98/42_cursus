#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
private :
	std::map<std::string, ATarget*> _generator;

	TargetGenerator(const TargetGenerator& t);
	TargetGenerator& operator=(const TargetGenerator& t);

public :
	TargetGenerator(void);
	~TargetGenerator(void);

	void learnTargetType(ATarget* target);
	void forgetTargetType(const std::string& name);
	ATarget* createTarget(const std::string& name);
};

#endif
