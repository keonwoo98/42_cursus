#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
	/*
	 * enable_if
	 */
	template <bool, class T = void>
	struct enable_if {};
	
	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	/*
	 * is_integral
	 */
}

#endif
