#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "iterator_base.hpp"
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
	public :
/*
 * Member types :
 */
		typedef T 							data_type;
		typedef node_color 					color_type;
		typedef RBtree_node<data_type>*		node_ptr;

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
		RBtree_node(data_type data) : _data(data), _color(BLACK), _parent(NULL), _left(NULL), _right(NULL) {}
		RBtree_node(const RBtree_node& x) : _data(x._data), _color(x._color) {}
		virtual ~RBtree_node() {}
	};

	template <typename T>
	class RBtree_iterator
	{
	public :
		typedef ft::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;

		node_type *node;
	};
};

#endif
