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
	public :
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair() : first() , second() {}

		template <typename U, typename V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second){};

		pair(const first_type& a, const second_type& b) : first(a), second(b){};

		pair &operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;

			return *this;
		}
	};

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

	template <typename T>
	void swap(T &a, T &b)
	{
		T c(a);
		a = b;
		b = c;
	}

	template <typename T1, typename T2>
	pair<T1, T2> make_pair(const T1 &x, const T2 &y)
	{
		return pair<T1, T2>(x, y);
	}
}

#endif
