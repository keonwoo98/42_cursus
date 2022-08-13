#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
	/**
	 * @brief Pair of values
	 * This class couples together a pair of values, which may be of different types (T1 and T2).
	 * @tparam T1 Type of member first, aliased as first_type.
	 * @tparam T2 Type of member second, aliased as second_type.
	 */
	template <typename T1, typename T2>
	struct pair
	{
/*
 * Member types :
 */
		typedef T1	first_type;
		typedef T2	second_type;

/*
 * Member variables :
 */
		first_type	first;
		second_type	second;

/*
 * Member functions :
 */
		/**
		 * @brief Default constructor
		 * Constructs a pair object.
		 */
		pair() : first() , second() {}

		/**
		 * @brief Copy / move constructor (and implicit conversion)
		 * Constructs a pair object.
		 * The object is initialized with the contents of the pr pair object.
		 * @tparam U 
		 * @tparam V 
		 * @param pr Another pair object.
		 */
		template <typename U, typename V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second){};

		/**
		 * @brief Initialization constructor
		 * Constructs a pair object.
		 * Member first is constructed with a and member second with b.
		 * @param a An object of the type of first, or some other type implicitly convertible to it.
		 * @param b An object of the type of second, or some other type implicitly convertible to it.
		 */
		pair(const first_type& a, const second_type& b) : first(a), second(b){};

		/**
		 * @brief Assign contents
		 * Assigns pr as the new content for the pair object.
		 * @param pr Another pair object.
		 * @return pair& 
		 */
		pair &operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;

			return *this;
		}
	};

/*
 * Non-member function overloads :
 */

	/**
	 * @brief Relational operators for pair
	 * Performs the appropriate comparison operation between the pair objects lhs and rhs.
	 * @tparam T1 
	 * @tparam T2 
	 * @param lhs pair object (to the left-hand side of the operator), having both the same template parameters (T1 and T2).
	 * @param rhs (to the right-hand side of the operator)
	 * @return true 
	 * @return false 
	 */
	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first ||
			(!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T1, typename T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}

/*
 * make_pair :
 */
	/**
	 * @brief Construct pair object
	 * Constructs a pair object with its first element set to x and its second element set to y.
	 * @tparam T1 
	 * @tparam T2 
	 * @param x Value for the members first, respectively, of the pair object being constructed.
	 * @param y Value for the members second, respectively, of the pair object being constructed.
	 * @return pair<T1, T2> 
	 */
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(const T1 &x, const T2 &y)
	{
		return pair<T1, T2>(x, y);
	}
}

#endif
