#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "-------------Brain Test-------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	delete j;
	delete i;

	std::cout << std::endl;

	std::cout << "-------------Array Test-------------" << std::endl;
	const Animal* animal[10];
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "i : " << i << std::endl;
		if (i % 2)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "i : " << i << std::endl;
		delete animal[i];
	}
	
	std::cout << std::endl;

	std::cout << "------------Casting Test------------" << std::endl;
	const Animal* c1 = new Cat();
	const Animal* c2 = new Cat(*dynamic_cast<Cat const *>(c1));
	std::cout << std::endl;
	delete c1;
	delete c2;

	std::cout << std::endl;

	std::cout << "-----------Deep copy Test-----------" << std::endl;
	Dog d1;
	Dog d2(d1);
	std::cout << std::endl;
	d1.setType("Type changed");
	std::cout << "Type : " << d1.getType() << std::endl;
	std::cout << "Type : " << d2.getType() << std::endl;

	std::cout << std::endl;

	for (int index = 0; index < 100; index++)
		std::cout << d1.getBrain()->getIdea(index) << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
