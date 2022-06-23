#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat kim("Kim", 150);
		Bureaucrat lee("Lee", 1);

		std::cout << kim << std::endl;
		std::cout << lee << std::endl;

		/* Exception */
		// kim.decrementGrade();
		// lee.incrementGrade();
		kim.incrementGrade();
		lee.decrementGrade();
		std::cout << kim << std::endl;
		std::cout << lee << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
