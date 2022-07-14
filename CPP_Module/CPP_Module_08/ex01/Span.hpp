#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private :
	std::vector<int> _v;

public :
	Span(void);
	Span(unsigned int N);
	Span(const Span& s);
	~Span(void);
	Span& operator=(const Span& s);
	void addNumber(int num);
	void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
	int shortestSpan(void);
	int longestSpan(void);

	class NoSpaceException : public std::exception
	{
	public :
		const char* what(void) const throw();
	};

	class NotEnoughElementException : public std::exception
	{
	public :
		const char* what(void) const throw();
	};
};

#endif
