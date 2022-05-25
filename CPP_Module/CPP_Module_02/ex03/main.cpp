#include "Point.hpp"

int main(void)
{
	// Point a(8, 3);
	// Point b(5, 9);
	// Point c(1, 1);
	// Point p1(6, 3);
	// Point p2(4, 1);
	Point a(0.0, 0.0);
	Point b(0.0, 4.0);
	Point c(5.0, 0.0);
	Point p1(1.0, 1.0);
	Point p2(-4.234, 1.181);

	if (bsp(a, b, c, p1))
		std::cout << "p1 is in the triangle" << std::endl;
	else
		std::cout << "p1 is out of the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "p2 is in the triangle" << std::endl;
	else
		std::cout << "p2 is out of the triangle" << std::endl;

	return 0;
}
