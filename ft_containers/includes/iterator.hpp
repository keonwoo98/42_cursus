#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iterator>

namespace ft
{
	/**
	 * @brief Empty class to identify the category of an iterator.
	 */
	// A class that provides a return type for iterator_category function that represents an input iterator.
	struct input_iterator_tag {};
	// A class that provides a return type for iterator_category function that represents an output iterator.
	struct output_iterator_tag {};
	// A class that provides a return type for iterator_category function that represents a forward iterator.
	struct forward_iterator_tag : public input_iterator_tag {};
	// A class that provides a return type for iterator_category function that represents a bidirectional iterator.
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	// A class that provides a return type for iterator_category function that represents a random-access iterator.
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/**
	 * @brief An empty base struct used to ensure that a user-defined
	 * iterator class works properly with iterator_traits.
	 * 
	 * @tparam Category The category of the iterator.
	 * Must be one of iterator category tags.
	 * @tparam T The type of the values that can be obtained by dereferencing the iterator.
	 * This type should be void for output iterators.
	 * @tparam Distance A type that can be used to identify distance between iterators.
	 * @tparam Pointer Defines a pointer to the type iterated over T.
	 * @tparam Reference Defines a reference to the type iterated over T.
	 */
	template <	typename Category, typename T,
				typename Distance = std::ptrdiff_t,
				typename Pointer = T*,
				typename Reference = T& >
	struct iterator
	{
		// A synonym for the template parameter Category
		typedef Category		iterator_category;
		// A synonym for the template parameter Type
		typedef T				value_type;
		// A synonym for the template parameter Distance
		typedef Distance		difference_type;
		// A synonym for the template parameter Pointer
		typedef Pointer			pointer;
		// A synonym for the template parameter Reference
		typedef Reference		reference;
	};

	/**
	 * @brief A template helper struct used to specify all the
	 * critical type definitions that an iterator should have.
	 * 
	 * @tparam Iterator 
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

	/**
	 * @brief The class template is an iterator adaptor that describes
	 * a reverse iterator object that behaves like a random-access or bidirectional
	 * iterator, only in reverse. It enables the backward traversal of a range.
	 * 
	 * @tparam Iterator 
	 */
	template <typename Iterator>
	class reverse_iterator
		: public iterator<	typename iterator_traits<Iterator>::iterator_category,
							typename iterator_traits<Iterator>::value_type,
							typename iterator_traits<Iterator>::difference_type,
							typename iterator_traits<Iterator>::pointer,
							typename iterator_traits<Iterator>::reference >
	{
	public :
		typedef Iterator												iterator_type;
		// typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		// typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
	
	protected :
		iterator_type		current;
	
	public :
		reverse_iterator() : current() {}

		explicit reverse_iterator(iterator_type it) : current(it) {}

		// reverse_iterator(const reverse_iterator& it) : current(it.current) {}

		template<typename Iter>
		reverse_iterator(const reverse_iterator<Iter>& it) : current(it.base()) {}

		virtual ~reverse_iterator() {}

		iterator_type base() const { return current; }

		reference operator*() const { Iterator tmp = current; return *--tmp; }
		pointer operator->() const { return &(operator*()); }
		reverse_iterator& operator++() { --current; return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp(*this); --current; return tmp; }
		reverse_iterator& operator--() { ++current; return *this; }
		reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++current; return tmp; }
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(current - n); }
		reverse_iterator& operator+=(difference_type n) { current -= n; return *this; }
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(current + n); }
		reverse_iterator& operator-=(difference_type n) { current += n; return (this); }
		reference operator[](difference_type n) const { return *(*this + n); }
	};

	template <typename Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() == rhs.base(); }
	
	template <typename Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() != rhs.base(); }
	
	template <typename Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() > rhs.base(); }
	
	template <typename Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() >= rhs.base(); }
	
	template <typename Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() < rhs.base(); }
	
	template <typename Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs.base() <= rhs.base(); }

	template <typename Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
										 const reverse_iterator<Iterator>& rev_it)
	{ return reverse_iterator<Iterator>(rev_it.base() - n); }

	template <typename Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}
}

#endif
