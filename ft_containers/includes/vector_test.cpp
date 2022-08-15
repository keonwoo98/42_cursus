#include "vector.hpp"
#include <vector>
#include <iostream>

template <typename T>
void print_info(std::vector<T> &v)
{
	std::cout << "std_vector size : " << v.size() << std::endl;
	std::cout << "std_vector capacity : " << v.capacity() << std::endl;
}

template <typename T>
void print_info(ft::vector<T> &v)
{
	std::cout << "ft_vector size : " << v.size() << std::endl;
	std::cout << "ft_vector capacity : " << v.capacity() << std::endl;
}

int main(void)
{
	std::vector<int> std_v;
	ft::vector<int> ft_v;

	// ===== vector push_back test =====
	std::cout << "===== vector push_back test=====" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std_v.push_back(i);
		ft_v.push_back(i);
		assert(std_v.size() == ft_v.size());
		assert(std_v.capacity() == ft_v.capacity());
	}
	print_info(std_v);
	print_info(ft_v);

	// ===== vector pop_back test =====
	std::cout << "===== vector pop_back test=====" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std_v.pop_back();
		ft_v.pop_back();
		assert(std_v.size() == ft_v.size());
		assert(std_v.capacity() == ft_v.capacity());
	}
	print_info(std_v);
	print_info(ft_v);

	return (0);
}
