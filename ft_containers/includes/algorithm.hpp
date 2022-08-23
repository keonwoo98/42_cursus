#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{
	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type difference(InputIterator first, InputIterator last)
	{
		typedef typename ft::iterator_traits<InputIterator>::difference_type size_type;
		size_type n = 0;
		for (; first != last; first++)
			n++;
		return n;
	}

	/**
	 * @brief Exchange values of two objects
	 * Exchanges the values of a and b.
	 * @tparam T 
	 * @param a Two objects, whose contents are swapped.
	 * @param b Two objects, whose contents are swapped.
	 */
	template <typename T>
	void swap(T& a, T& b)
	{
		T c = a;
		a = b;
		b = c;
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

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2,
								 Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}

#endif
