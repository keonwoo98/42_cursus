#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public :
		typedef T						value_type;
		typedef Alloc					allocator_type;
	};
}

#endif
