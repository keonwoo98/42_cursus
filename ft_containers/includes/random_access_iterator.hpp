#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	/**
	 * @brief 
	 * 
	 * @tparam Iterator 
	 * @tparam Container 
	 */
	template <typename Iterator, typename Container>
	class random_access_iterator
		: public iterator<	typename iterator_traits<Iterator>::iterator_category,
							typename iterator_traits<Iterator>::value_type,
							typename iterator_traits<Iterator>::difference_type,
							typename iterator_traits<Iterator>::pointer,
							typename iterator_traits<Iterator>::reference >
	{
	public :
		// typedef Iterator												iterator_type;
		// typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		// typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
	
	protected :
		Iterator		_current;
	
	public :
		random_access_iterator() : _current(Iterator()) {}

		explicit random_access_iterator(const Iterator& it) : _current(it) {}

		template<typename Iter>
		random_access_iterator(const random_access_iterator<Iter, Container>& it) : _current(it.base()) {}

		virtual ~random_access_iterator() {}

		const Iterator& base() const { return _current; }

		reference operator*() const { return *_current; }
		pointer operator->() const { return _current; }
		random_access_iterator& operator++() { ++_current; return *this; }
		random_access_iterator operator++(int) { return random_access_iterator(_current++); }
		random_access_iterator& operator--() { --_current; return *this; }
		random_access_iterator operator--(int) { return random_access_iterator(_current--); }
		random_access_iterator operator+(const difference_type& n) const { return random_access_iterator(_current + n); }
		random_access_iterator& operator+=(const difference_type& n) { _current += n; return *this; }
		random_access_iterator operator-(const difference_type& n) const { return random_access_iterator(_current - n); }
		random_access_iterator& operator-=(const difference_type& n) { _current -= n; return *this; }
		difference_type operator-(const random_access_iterator& it) const { return _current - it._current; }
		reference operator[](const difference_type& n) const { return _current[n]; }
	};

	template <typename Iterator, typename Container>
	bool operator==(const random_access_iterator<Iterator, Container>& lhs,
					const random_access_iterator<Iterator, Container>& rhs)
	{ return lhs.base() == rhs.base(); }
	
	template <typename Iterator, typename Container>
	bool operator!=(const random_access_iterator<Iterator, Container>& lhs,
					const random_access_iterator<Iterator, Container>& rhs)
	{ return lhs.base() != rhs.base(); }
	
	template <typename Iterator, typename Container>
	bool operator<(const random_access_iterator<Iterator, Container>& lhs,
					const random_access_iterator<Iterator, Container>& rhs)
	{ return lhs.base() < rhs.base(); }
	
	template <typename Iterator, typename Container>
	bool operator<=(const random_access_iterator<Iterator, Container>& lhs,
					const random_access_iterator<Iterator, Container>& rhs)
	{ return lhs.base() <= rhs.base(); }
	
	template <typename Iterator, typename Container>
	bool operator>(const random_access_iterator<Iterator, Container>& lhs,
					const random_access_iterator<Iterator, Container>& rhs)
	{ return lhs.base() > rhs.base(); }
	
	template <typename Iterator, typename Container>
	bool operator>=(const random_access_iterator<Iterator, Container>& lhs,
					const random_access_iterator<Iterator, Container>& rhs)
	{ return lhs.base() >= rhs.base(); }

	template <typename Iterator, typename Container>
	random_access_iterator<Iterator, Container> operator+(
		typename random_access_iterator<Iterator, Container>::difference_type n,
		const random_access_iterator<Iterator, Container>& it)
	{ return random_access_iterator<Iterator, Container>(it.base() + n); }

	template <typename Iterator, typename Container>
	typename random_access_iterator<Iterator, Container>::difference_type operator-(
		const random_access_iterator<Iterator, Container>& lhs,
		const random_access_iterator<Iterator, Container>& rhs)
	{ return lhs.base() - rhs.base(); }
}

#endif
