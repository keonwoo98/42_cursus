#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	/* Error */
	// const Animal* animal = new Animal();
	// animal->makeSound();
	// delete animal;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;
	
	return 0;
}
