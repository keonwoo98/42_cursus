#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("b1", 150);
		Bureaucrat b2("b2", 1);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << std::endl;

		/* Exception */
		b1.decrementGrade();
		b2.incrementGrade();
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b3("b3", 10);
		Bureaucrat b4(b3);

		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
		std::cout << std::endl;

		b3.incrementGrade();
		b4.decrementGrade();
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
