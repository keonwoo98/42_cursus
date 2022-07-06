#include "Intern.hpp"

int main(void)
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 50);
	Bureaucrat b3("b3", 150);

	try
	{
		std::cout << "===========ShrubberyCreationForm Success Test===========" << std::endl;
		ShrubberyCreationForm s1("Shrubbery");
		s1.beSigned(b1);
		s1.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "============ShrubberyCreationForm Fail Test============" << std::endl;
		ShrubberyCreationForm s2("Shrubbery");
		s2.beSigned(b3);
		s2.execute(b3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try
	{
		std::cout << "============RobotomyRequestForm Success Test============" << std::endl;
		RobotomyRequestForm r("Robotomy");
		r.beSigned(b1);
		r.execute(b1);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=============RobotomyRequestForm Fail Test=============" << std::endl;
		RobotomyRequestForm r("Robotomy");
		r.beSigned(b2);
		r.execute(b2);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try
	{
		std::cout << "===========PresidentialPardonForm Success Test===========" << std::endl;
		PresidentialPardonForm p("Presidential");
		p.beSigned(b1);
		p.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "============PresidentialPardonForm Fail Test============" << std::endl;
		PresidentialPardonForm p("Presidential");
		p.beSigned(b2);
		p.execute(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try
	{
		std::cout << "==============Bureaucrat Execute Form Test==============" << std::endl;
		PresidentialPardonForm p("PP Form");
		b2.signForm(p);
		b2.executeForm(p);
		std::cout << std::endl;
		std::cout << p << std::endl;
		std::cout << std::endl;
		b1.signForm(p);
		b1.executeForm(p);
		std::cout << std::endl;
		std::cout << p << std::endl;
		std::cout << std::endl;
		b3.executeForm(p);
		std::cout << std::endl;
		std::cout << p << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	return 0;
}
