#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "reverse_iterator.hpp"
#include "utility.hpp"
#include "type_traits.hpp"
#include <memory>

namespace ft
{
	enum node_color
	{ RED, BLACK };

	template <typename T>
	class RBtree_node
	{
/*
 * Member types :
 */
	public :
		typedef T 								data_type;
		typedef node_color 						color_type;
		typedef RBtree_node<data_type>*			node_ptr;
		typedef const RBtree_node<data_type>*	const_node_ptr;

/*
 * Member variables :
 */
		data_type 							_data;
		color_type 							_color;
		node_ptr							_parent;
		node_ptr							_left;
		node_ptr							_right;

/*
 * Member functions :
 */
		RBtree_node() : _data(), _color(BLACK), _parent(), _left(), _right() {}
		
		RBtree_node(const RBtree_node& n)
			: _data(n._data), _color(n._color), _parent(n._parent), _left(n._left), _right(n._right) {}
		
		virtual ~RBtree_node() {}
		
		RBtree_node& operator=(const RBtree_node& n)
		{
			if (this != &n)
			{
				_data = n._data;
				_color = n._color;
				_parent = n._parent;
				_left = n._left;
				_right = n._right;
			}
			return *this;
		}

		void flip_color()
		{
			_color = _color == RED ? BLACK : RED;
		}

		node_ptr tree_min(node_ptr ptr)
		{
			while (ptr->_left != NULL)
				ptr = ptr->_left;
			return ptr;
		}

		node_ptr tree_max(node_ptr ptr)
		{
			while (ptr->_right != NULL)
				ptr = ptr->_right;
			return ptr;
		}
	};

	template <typename Node_ptr, typename Value>
	class RBtree_iterator
	{
/*
 * Member types :
 */
	public :
		typedef ft::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;
		typedef Value								value_type;
		typedef Value*								pointer;
		typedef Value&								reference;

/*
 * Member variables :
 */
	private :
		Node_ptr	_node;

/*
 * Member functions :
 */
	public :
		RBtree_iterator() : node() {}

		RBtree_iterator(const RBtree_iterator& it) : _node(it._node) {}

		RBtree_iterator(const Node_ptr& val) : _node(val) {}

		RBtree_iterator& operator=(const RBtree_iterator& it)
		{
			if (this != &it)
				_node = it._node;
			return *this;
		}

		RBtree_iterator& operator=(const Node_ptr& p)
		{
			_node = p;
			return *this;
		}

		reference operator*() const { return _node->_data; }
		pointer operator->() const { return &_node->_data; }

		RBtree_iterator& operator++()
		{
			if (_node->_right != NULL)
				_node = tree_min<value_type>(_node->_right);
			else
			{
				Node_ptr p = _node->_parent;
				while (p != NULL && _node == p->_right)
				{
					_node = p;
					p = p->_parent;
				}
				_node = p;
			}
			return *this;
		}

		RBtree_iterator operator++(int)
		{
			RBtree_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		RBtree_iterator& operator--()
		{
			if (_node->_left != NULL)
				_node = tree_max<value_type>(_node->_left);
			else
			{
				Node_ptr p = _node->_parent;
				while (p != NULL && _node == p->_left)
				{
					_node = p;
					p = p->parent;
				}
				_node = p;
			}
			return *this;
		}

		RBtree_iterator operator--(int)
		{
			RBtree_iterator tmp(*this);
			--(*this);
			return tmp;
		}

		Node_ptr base() const
		{
			return _node;
		}
	};

	template<typename Node_ptr, typename Value>
	inline bool
		operator==(const RBtree_iterator<Node_ptr, Value>& rhs, const RBtree_iterator<Node_ptr, Value>& lhs)
	{ return rhs.base() == lhs.base(); }

	template<typename Node_ptr, typename Value>
	inline bool
		operator!=(const RBtree_iterator<Node_ptr, Value>& rhs, const RBtree_iterator<Node_ptr, Value>& lhs)
	{ return rhs.base() != lhs.base(); }

	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class RBtree
	{
/*
 * Member types :
 */
	public :
		typedef ft::RBtree_node<T>											node_type;
		typedef T															value_type;
		typedef Compare														value_compare;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::size_type							size_type;
		typedef typename allocator_type::differenct_type					difference_type;
		typedef typename node_type::node_ptr								node_ptr;
		typedef typename node_type::const_node_ptr							const_node_ptr;

		typedef ft::RBtree_iterator<node_ptr, value_type>					iterator;
		typedef ft::RBtree_iterator<const node_ptr, const value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

/*
 * Member variables :
 */
	private :
		size_type				_size;
		node_type				_parent;
		node_ptr				_begin_node;
		value_compare			_compare;
		allocator_type			_allocator;
		node_allocator_type		_node_allocator;

/*
 * Member functions :
 */
	public :
		// Constructors
		explicit RBtree(const value_compare& comp, const allocator_type& alloc)
			: _size(), _parent(), _begin_node(&_parent), _compare(comp), _allocator(alloc), _node_allocator(alloc) {}
		
		RBtree(const RBtree& t)
			: _size(), _parent(), _begin_node(&_parent), _compare(t._compare), _allocator(t._allocator), _node_allocator(t._node_allocator)
		{
			if (t.root() != NULL)
			{
				this->root() = this->copy(t.root());
				this->root()->_parent = &this->_parent;
			}
		}

		// Destructor
		~RBtree()
		{
			if (this->root() != NULL)
			{
				this->destroy(this->root());
				this->root() = NULL;
				this->_begin_node = this->end_node();
			}
		}

		// Operator Overload
		RBtree& operator=(const RBtree& t)
		{
			if (this != &t)
			{
				this->clear();
				this->_compare = t._compare;
				if (t.root() != NULL)
				{
					this->root() = this->copy(t.root());
					this->root()->_parent = &this->_parent;
				}
			}
			return *this;
		}

		// Iterators
		iterator begin() { return iterator(this->_begin_node); }
		const iterator begin() const { return const_iterator(this->_begin_node); }
		iterator end() { return iterator(&this->_parent); }
		const_iterator end() const { return const_iterator(&this->_parent); }
		reverse_iterator rbegin() { return reverse_iterator(this->end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

		// Capacity
		bool empty() const { return this->_size == 0; }
		size_type size() const { return this->_size; }
		size_type max_size() const { return-> this->_allocator.max_size(); }

		// Modifiers
		ft::pair<iterator, bool> insert(const value_type& val);
		iterator insert(iterator posision, const value_type& val);
		template<typename InputIterator>
		void insert (InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const value_type& val);
		void swap(RBtree& t);
		void clear();

		// Observer
		value_compare value_comp() const { return this->_compare; }

		// Operations
		iterator find(const value_type& val)
		{
			node_ptr node = this->root();

			while (node != NULL)
			{
				if (this->_compare(node->_data, val))
					node = node->_right;
				else if (this->_compare(val, node->_data))
					node = node->_left;
				else
					return iterator(node);
			}
			return this->end();
		}

		const_iterator find(const value_type& val) const
		{
			const_node_ptr node = this->root();

			while (node != NULL)
			{
				if (this->_compare(node->_data, val))
					node = node->_right;
				else if (this->_compare(val, node->_data))
					node = node->_left;
				else
					return const_iterator(node);
			}
			return this->end();
		}

		size_type count(const value_type& val)
		{ return this->find(val) == this->end() ? 0 : 1; }

		iterator lower_bound(const value_type& val)
		{
			node_ptr node = this->root();
			node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (!this->_compare(node->_data, val))
				{
					pos = node;
					node = node->_left;
				}
				else
					node = node->_right;
			}
			return iterator(pos);
		}

		const_iterator lower_bound(const value_type& val) const
		{
			const_node_ptr node = this->root();
			const_node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (!this->_compare(node->_data, val))
				{
					pos = node;
					node = node->_left;
				}
				else
					node = node->_right;
			}
			return const_iterator(pos);
		}

		iterator upper_bound(const value_type& val)
		{
			node_ptr node = this->root();
			node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (!this->_compare(val, node->_data))
				{
					pos = node;
					node = node->_left;
				}
				else
					node = node->_right;
			}
			return iterator(pos);
		}

		const_iterator upper_bound(const value_type& val) const
		{
			const_node_ptr node = this->root();
			const_node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (!this->_compare(val, node->_data))
				{
					pos = node;
					node = node->_left;
				}
				else
					node = node->_right;
			}
			return const_iterator(pos);
		}

		ft::pair<iterator, iterator> equal_range(const value_type& val)
		{
			node_ptr node = this->root();
			node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (this->_compare(val, node->_data))
				{
					pos = node;
					node = node->_left;
				}
				else if (this->_compare(node->_data, val))
					node = node->_right;
				else
					return ft::make_pair(iterator(node), iterator(node->_right == NULL ? pos : tree_min<value_type>(node->_right)));
			}
			return ft::make_pair(iterator(pos), iterator(pos));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const value_type& val) const
		{
			node_ptr node = this->root();
			node_ptr pos = this->end_node();

			while (node != NULL)
			{
				if (this->_compare(val, node->_data))
				{
					pos = node;
					node = node->_left;
				}
				else if (this->_compare(node->_data, val))
					node = node->_right;
				else
					return ft::make_pair(const_iterator(node), const_iterator(node->_right == NULL ? pos : tree_min<value_type>(node->_right)));
			}
			return ft::make_pair(const_iterator(pos), const_iterator(pos));
		}
	};
};

#endif
