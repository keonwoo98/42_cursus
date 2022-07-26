#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
	/**
	 * @brief enable_if
	 * The type T is enabled as member type enable_if::type if Cond is true.
	 * Otherwise, enable_if::type is not defined.
	 */
	template <bool Cond, class T = void>
	struct enable_if {};
	
	template <class T>
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
	struct is_integral<long long int> : public true_type {};
	template <>
	struct is_integral<unsigned char> : public true_type {};
	template <>
	struct is_integral<unsigned short int> : public true_type {};
	template <>
	struct is_integral<unsigned int> : public true_type {};
	template <>
	struct is_integral<unsigned long int> : public true_type {};
	template <>
	struct is_integral<unsigned long long int> : public true_type {};

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type difference(InputIterator first, InputIterator last)
	{
		typedef typename ft::iterator_traits<InputIterator>::difference_type size_type;
		size_type n = 0;
		for (; first != last; first++)
			n++;
		return n;
	}

	/**
	 * @brief Test whether the elemets in two ranges are equal (Equality)
	 * Compares the elements in the range [first, last1) with those in the range
	 * beginning at first2, and returns true if all of the elements in both ranges match.
	 * @tparam InputIterator1 
	 * @tparam InputIterator2 
	 * @param first1 Input iterator to the initial position of the first sequence.
	 * @param last1 Input iterator to the final position of the first sequence.
	 * @param first2 Input iterator to the initial position of the second sequence.
	 * @return true 
	 * @return false 
	 */
	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	/**
	 * @brief Test whether the elemets in two ranges are equal (Predicate)
	 * Compares the elements in the range [first, last1) with those in the range
	 * beginning at first2, and returns true if all of the elements in both ranges match.
	 * @tparam InputIterator1 
	 * @tparam InputIterator2 
	 * @tparam BinaryPredicate 
	 * @param first1 Input iterator to the initial position of the first sequence.
	 * @param last1 Input iterator to the final position of the first sequence.
	 * @param first2 Input iterator to the initial position of the second sequence.
	 * @param pred Binary function that accepts two elements as argument(one of each of
	 * the two sequences, int the same order), and returns a value convertible to bool.
	 * @return true 
	 * @return false 
	 */
	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	/**
	 * @brief Lexicographical less-than comparison
	 * Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
	 * @tparam InputIterator1 
	 * @tparam InputIterator2 
	 * @param first1 Input iterator to the initial position of the first sequence.
	 * @param last1 Input iterator to the final position of the first sequence.
	 * @param first2 Input iterator to the initial position of the second sequence.
	 * @param last2 Input iterator to the final position of the second sequence.
	 * @return true 
	 * @return false 
	 */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}

#endif
