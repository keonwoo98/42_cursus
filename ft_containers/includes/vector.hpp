#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "random_access_iterator.hpp"
#include "utils.hpp"
#include <memory>

namespace ft
{
	/**
	 * @brief 
	 * 
	 * @tparam T 
	 * @tparam Alloc 
	 */
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public :
		typedef T																value_type;
		typedef Alloc															allocator_type;
		typedef std::ptrdiff_t													difference_type;
		typedef std::size_t														size_type;
		typedef typename allocator_type::reference								reference;
		typedef typename allocator_type::const_reference						const_reference;
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef ft::random_access_iterator<value_type, allocator_type>			iterator;
		typedef ft::random_access_iterator<const value_type, allocator_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;

	protected :
		allocator_type		_alloc;
		pointer				_start;
		pointer				_end;
		pointer				_end_capacity;

	public :
		explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _start(0), _end(0), _end_capacity(0) {}
		
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
			: _alloc(alloc)
		{
			this->_start = this->_alloc.allocate(n);
			this->_end = this->_start;
			this->_end_capacity = this->_start + n;
			while (n--)
				this->_alloc.construct(this->_end++, val);
		}
		
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);
		
		vector(const vector& x);
	};
}

#endif
