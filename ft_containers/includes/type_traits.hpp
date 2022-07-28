#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include "iterator_base.hpp"
#include <cstdint>

namespace ft
{
	/**
	 * @brief enable_if
	 * The type T is enabled as member type enable_if::type if Cond is true.
	 * Otherwise, enable_if::type is not defined.
	 */
	template <bool Cond, typename T = void>
	struct enable_if {};
	
	template <typename T>
	struct enable_if<true, T> { typedef T type; };

	/**
	 * @brief is_integral
	 * Traits class that identifies whether T is an integral type.
	 * It inherits from integral_constant as being either true_type or false_type,
	 * depending on whether T is an integral type.
	 */
	struct false_type
	{
		typedef bool value_type;
		typedef false_type type;
		static const value_type value = false;
	};

	struct true_type
	{
		typedef bool value_type;
		typedef true_type type;
		static const value_type value = true;
	};

	template <typename T>
	struct is_integral : public false_type {};
	template <>
	struct is_integral<bool> : public true_type {};
	template <>
	struct is_integral<char> : public true_type {};
	template <>
	struct is_integral<char16_t> : public true_type {};
	template <>
	struct is_integral<char32_t> : public true_type {};
	template <>
	struct is_integral<wchar_t> : public true_type {};
	template <>
	struct is_integral<signed char> : public true_type {};
	template <>
	struct is_integral<short int> : public true_type {};
	template <>
	struct is_integral<int> : public true_type {};
	template <>
	struct is_integral<long int> : public true_type {};
	template <>
	struct is_integral<int64_t> : public true_type {};
	template <>
	struct is_integral<unsigned char> : public true_type {};
	template <>
	struct is_integral<unsigned short int> : public true_type {};
	template <>
	struct is_integral<unsigned int> : public true_type {};
	template <>
	struct is_integral<unsigned long int> : public true_type {};
	template <>
	struct is_integral<uint64_t> : public true_type {};
}

#endif
