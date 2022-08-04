#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::TargetGenerator(const TargetGenerator& t) : _generator(t._generator) {}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& t)
{
	_generator = t._generator;
	return *this;
}

TargetGenerator::~TargetGenerator(void) {}

void TargetGenerator::learnTargetType(ATarget* target)
{
	_generator.insert(std::make_pair(target->getType(), target));
}

void TargetGenerator::forgetTargetType(const std::string& name)
{
	_generator.erase(name);
}

ATarget* TargetGenerator::createTarget(const std::string& name)
{
	std::map<std::string, ATarget*>::iterator it;

	it = _generator.find(name);
	if (it != _generator.end())
		return it->second;
	return NULL;
}
