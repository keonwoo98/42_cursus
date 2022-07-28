#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_base.hpp"

namespace ft
{
	/**
	 * @brief Reverse iterator
	 * This class reverses the direction in which a bidirectional
	 * or random-access iterator iterates through a range.
	 * @tparam Iterator A bidirectional iterator type or a random-access iterator.
	 */
	template <typename Iterator>
	class reverse_iterator
		: public ft::iterator<	typename ft::iterator_traits<Iterator>::iterator_category,
								typename ft::iterator_traits<Iterator>::value_type,
								typename ft::iterator_traits<Iterator>::difference_type,
								typename ft::iterator_traits<Iterator>::pointer,
								typename ft::iterator_traits<Iterator>::reference >
	{

/*
 * Member types :
 */
	public :
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

/*
 * Member variables :
 */	
	protected :
		iterator_type		_current;
	
/*
 * Member functions :
 */
	public :
		/**
		 * @brief Default constructor
		 * Constructs a reverse iterator that points to no object.
		 * The internal base iterator is value-initialized.
		 */
		reverse_iterator() : _current() {}

		/**
		 * @brief Initalization constructor
		 * Constructs a reverse iterator from some original iterator it.
		 * @param it An iterator, whose sense of iteration is inverted in the constructed object.
		 */
		explicit reverse_iterator(iterator_type it) : _current(it) {}

		/**
		 * @brief Copy / type-cast constructor
		 * Constructs a reverse iterator from some other reverse iterator.
		 * @tparam Iter 
		 * @param rev_it An iterator of a reverse_iterator type, whose sense of iteration is preserved.
		 */
		template<typename Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _current(rev_it.base()) {}

		/**
		 * @brief Desturctor
		 * Destroy the reverse iterator object.
		 */
		virtual ~reverse_iterator() {}

		/**
		 * @brief Return base iterator
		 * Returns a copy of the base iterator.
		 * @return iterator_type 
		 */
		iterator_type base() const { return _current; }

		/**
		 * @brief Dereference iterator
		 * Returns a reference to the element pointed to by the iterator.
		 * @return reference 
		 */
		reference operator*() const { Iterator tmp = _current; return *--tmp; }

		/**
		 * @brief Dereference iterator
		 * Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
		 * @return pointer 
		 */
		pointer operator->() const { return &(operator*()); }

		/**
		 * @brief Increment iterator position
		 * Advances the reverse_iterator by one position.
		 * @return reverse_iterator& / reverse_iterator
		 */
		reverse_iterator& operator++() { --_current; return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp(*this); --_current; return tmp; }

		/**
		 * @brief Decrease iterator position
		 * Decreases the reverse_iterator by one position.
		 * @return reverse_iterator& / reverse_iterator
		 */
		reverse_iterator& operator--() { ++_current; return *this; }
		reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++_current; return tmp; }

		/**
		 * @brief Addition operator
		 * Returns a reverse iterator pointing to the element located n
		 * positions away from the element the iterator currently points to.
		 * @param n Number of elements to offset.
		 * @return reverse_iterator 
		 */
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(_current - n); }

		/**
		 * @brief Advance iterator
		 * Advances the reverse_iterator by n element positions.
		 * @param n Number of elements to offset.
		 * @return reverse_iterator& 
		 */
		reverse_iterator& operator+=(difference_type n) { _current -= n; return *this; }

		/**
		 * @brief Subtraction operator
		 * Returns a reverse iterator pointing to the element located n
		 * positions before the element the iterator currently points to.
		 * @param n Number of elements to offset.
		 * @return reverse_iterator 
		 */
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(_current + n); }

		/**
		 * @brief Retrocede iterator
		 * Descreases the reverse_iterator by n element positions.
		 * @param n Number of elements to offset.
		 * @return reverse_iterator& 
		 */
		reverse_iterator& operator-=(difference_type n) { _current += n; return *this; }

		/**
		 * @brief Dereference iterator with offset
		 * Accesses the element located n positions away from the element currently pointed to by the iterator.
		 * @param n Number of elements to offset.
		 * @return reference 
		 */
		reference operator[](difference_type n) const { return *(*this + n); }
	};

/*
* Non-Member overloads :
*/

	/**
	 * @brief Relational operators for reverse_iterator
	 * Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	 * @tparam Iterator 
	 * @param lhs reverse_iterator objects (to the left-hand side of the operator), having both the same template parameter (Iterator).
	 * @param rhs (to the right-hand side of the operator)
	 * @return true 
	 * @return false 
	 */
	template <typename Iterator1, typename Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{ return lhs.base() == rhs.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{ return lhs.base() != rhs.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{ return lhs.base() > rhs.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{ return lhs.base() >= rhs.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{ return lhs.base() < rhs.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{ return lhs.base() <= rhs.base(); }

	/**
	 * @brief Addition operator
	 * Returns a reverse iterator pointing to the element located n
	 * positions away from the element pointed to by rev_it.
	 * @tparam Iterator 
	 * @param n Number of elements to offset.
	 * @param rev_it Reverse iterator.
	 * @return reverse_iterator<Iterator> 
	 */
	template <typename Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
											const reverse_iterator<Iterator> &rev_it)
	{ return reverse_iterator<Iterator>(rev_it.base() - n); }

	/**
	 * @brief Subtraction operator
	 * Returns the distance between lhs and rhs.
	 * @tparam Iterator 
	 * @param lhs reverse_iterator objects (to the left--hand side of the operator), having both the same template parameter (Iterator).
	 * @param rhs (to the right--hand side of the operator)
	 * @return reverse_iterator<Iterator>::difference_type 
	 */
	template <typename Iterator1, typename Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(
		const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{ return rhs.base() - lhs.base(); }
}

#endif
