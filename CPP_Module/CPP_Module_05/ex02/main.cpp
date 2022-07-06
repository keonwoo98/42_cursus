#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 50);
	Bureaucrat b3("b3", 150);

	try
	{
		std::cout << "=======ShrubberyCreationForm Test=======" << std::endl;
		ShrubberyCreationForm s("Shrubbery");
		s.beSigned(b1);
		s.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "========RobotomyRequestForm Test========" << std::endl;
		RobotomyRequestForm r("Robotomy");
		r.beSigned(b2);
		r.execute(b2);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=======PresidentialPardonForm Test=======" << std::endl;
		PresidentialPardonForm p("Presidential");
		p.beSigned(b1);
		p.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
