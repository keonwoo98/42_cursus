#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Not Found";
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	
	if (iter == container.end())
		throw NotFoundException();
	return iter;
}

#endif
