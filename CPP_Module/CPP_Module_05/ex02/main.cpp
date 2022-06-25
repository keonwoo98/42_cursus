#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("b1", 30);
		Form f1("f1", 50, 70);
		Form f2("f2", 10, 50);
		Form f3(f1);
		Form f4 = f2;

		b1.signForm(f1);
		b1.signForm(f2);
		std::cout << std::endl;

		std::cout << f1 << std::endl;
		std::cout << std::endl;
		std::cout << f2 << std::endl;
		std::cout << std::endl;
		std::cout << f3 << std::endl;
		std::cout << std::endl;
		std::cout << f4 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
