#include <iostream>
#include <ctime>
#include <fstream>

#ifdef STD_MODE
#include <map>
#include <stack>
#include <vector>
#include <set>
#define NAMESPACE std
#define TIME_DIFF "std_time"
#define MODE 1
#define _c c
#else
#include "../includes/utility.hpp"
#include "../includes/map.hpp"
#include "../includes/stack.hpp"
#include "../includes/vector.hpp"
#include "../includes/set.hpp"
#define NAMESPACE ft
#define TIME_DIFF "ft_time"
#define MODE 0
#endif

void vector_tests(void)
{
	NAMESPACE::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);

	NAMESPACE::vector<int>::iterator it;
	it = v.begin();
	std::cout << *it << std::endl;
	it = v.end();
	it--;
	std::cout << *it << std::endl;
	v.pop_back();
	std::cout << v.back() << std::endl;
	v.insert(v.begin(), 100);
	std::cout << v[0] << std::endl;
	std::cout << v.size() << std::endl;
	v.resize(100);
	std::cout << v.size() << std::endl;
	NAMESPACE::vector<int> copy;
	copy.assign(v.begin(), v.end());
	if (v == copy)
		std::cout << "same" << std::endl;
	copy.erase(copy.begin());
	std::cout << copy.front() << std::endl;
	v.clear();
	std::cout << v.size() << std::endl;
}

void stack_tests(void)
{
	NAMESPACE::stack<int> st1;
	NAMESPACE::stack<int> st2;

	for (int i = 0; i < 10; i++)
	{
		st1.push(i);
		st2.push(i);
	}
	
	std::cout << st1.empty() << std::endl;
	std::cout << st1.size() << std::endl;
	std::cout << st1.top() << std::endl;
	st1.pop();
	st1.pop();
	std::cout << st1.size() << std::endl;
	std::cout << st1.top() << std::endl;
	if (st1 != st2)
		std::cout << "different" << std::endl;
}

void map_tests(void)
{
	NAMESPACE::map<int, int> m;

	for (int i = 10; i > 0; i--)
		m.insert(NAMESPACE::make_pair(i, i * 10));
	
	NAMESPACE::map<int, int>::iterator it;
	it = m.begin();
	std::cout << it->first << it->second << std::endl;
	m.erase(m.begin(), ++m.begin());
	std::cout << m.size() << std::endl;
	NAMESPACE::map<int, int> copy(m);
	m.swap(copy);
	if (m == copy)
		std::cout << "same" << std::endl;
	m.clear();
	std::cout << m.size() << std::endl;
}

void set_tests(void)
{
	NAMESPACE::set<int> s;

	for (int i = 10; i > 0; i--)
		s.insert(i);
	NAMESPACE::set<int>::iterator it;
	it = s.begin();
	std::cout << *it << std::endl;
	NAMESPACE::set<int> copy;
	copy = s;
	s.erase(s.begin(), s.end());
	std::cout << s.size() << std::endl;
	if (s != copy)
		std::cout << "different" << std::endl;
	std::cout << copy.count(1) << std::endl;
	std::cout << s.empty() << std::endl;
}

int main(int argc, char** argv)
{
	clock_t start = clock();

	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	vector_tests();
	stack_tests();
	map_tests();
	set_tests();

	clock_t end = clock();
	std::ofstream out(TIME_DIFF, std::ofstream::out | std::ofstream::trunc);
	out << TIME_DIFF << ": " << end - start << std::endl;
	out.close();
	return (0);
}
