#ifndef ITERATOR_BASE_HPP
#define ITERATOR_BASE_HPP

#include <cstddef>

namespace ft
{
	/**
	 * @brief Iterator categories
	 * Iterators are classified into five categories depending on the functionality they implement.
	 * 
	 * Input and output iterators are the most limited types of iterators:
	 * they can perform sequential single-pass input or output operations.
	 * 
	 * Forward iterators have all the functionality of input iterators and -if they are
	 * not constant iterators- also the functionality of output iterators, although they
	 * are limited to one direction in which to iterate through a range (forward).
	 * 
	 * Bidirectional iterators are like forward iterators but can also be iterated through backwards.
	 * 
	 * Random-access iterators implement all the functionality of bidirectional iterators,and also
	 * have the ability to access ranges non-sequentially: distant elements can be accessed directly
	 * by applying an offset value to an iterator without iterating through all the elements in between.
	 */
	// Empty class to identify the category of an iterator as an input iterator.
	struct input_iterator_tag {};
	// Empty class to identify the category of an iterator as an output iterator.
	struct output_iterator_tag {};
	// Empty class to identify the category of an iterator as a forward iterator.
	struct forward_iterator_tag : public input_iterator_tag {};
	// Empty class to identify the category of an iterator as a bidirectional iterator.
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	// Empty class to identify the category of an iterator as a random-access iterator.
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/**
	 * @brief Iterator base class
	 * This is a base class template that can be used to derive iterator classes from it.
	 * @tparam Category Category to which the iterator belongs to.
	 * Must be one of iterator category tags.
	 * @tparam T Type of elements pointed by the iterator.
	 * @tparam Distance Type to represent the difference between two iterators.
	 * @tparam Pointer Type to represent a pointer to an element pointed by the iterator.
	 * @tparam Reference Type to represent a reference to an element pointed by the iterator.
	 */
	template <	typename Category, typename T,
				typename Distance = std::ptrdiff_t,
				typename Pointer = T*,
				typename Reference = T& >
	struct iterator
	{
		typedef Category		iterator_category;
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef Reference		reference;
	};

	/**
	 * @brief Iterator traits
	 * Traits class defining properties of iterators.
	 * @tparam Iterator 
	 * iterator_category : The iterator category.
	 * value_type : The type of the element the iterator can point to.
	 * difference_type : Type to express the result of subtracting one iterator from another.
	 * pointer : The type of a pointer to an element the iterator can point to.
	 * reference : The type of a reference to an element the iterator can point to.
	 */
	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T*										pointer;
		typedef T&										reference;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef const T*								pointer;
		typedef const T&								reference;
	};
}

#endif
