#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("b1", 50);
		Bureaucrat b2("b2", 100);
		Form f1("f1", 150, 1);
		Form f2("f2", 1, 150);
		Form f3(f1);
		Form f4 = f2;

		b1.signForm(f1);
		b2.signForm(f2);
		std::cout << std::endl;

		std::cout << f1 << std::endl;
		std::cout << std::endl;
		std::cout << f2 << std::endl;
		std::cout << std::endl;
		std::cout << f3 << std::endl;
		std::cout << std::endl;
		std::cout << f4 << std::endl;
		std::cout << std::endl;

		/* Exception */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
