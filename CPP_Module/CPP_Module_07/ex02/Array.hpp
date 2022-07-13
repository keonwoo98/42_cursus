#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <class T>
class Array
{
private :
	int _size;
	T* _arr;
public :
	Array(void) : _size(0), _arr(NULL) {}
	Array(unsigned int n) : _size(n), _arr(NULL)
	{
		if (_size)
			_arr = new T[_size];
	}
	Array(const Array& a) : _size(a._size), _arr(NULL)
	{
		if (_size)
			_arr = new T[_size];
		for (int i = 0 ; i < _size ; i++)
			_arr[i] = a[i];
	}
	~Array(void)
	{
		if (_size)
		{
			delete[] _arr;
			_arr = NULL;
		}
	}
	Array& operator=(const Array& a)
	{
		if (this != &a)
		{
			if (_size)
			{
				delete[] _arr;
				_arr = NULL;
			}
			_size = a.size();
			if (_size)
				_arr = new T[_size];
			for (int i = 0 ; i < _size ; i++)
				_arr[i] = a[i];
		}
		return *this;
	}
	T& operator[](int idx)
	{
		if (idx < 0 || idx >= _size)
			throw OutOfBoundException();
		return _arr[idx];
	}
	const T& operator[](int idx) const
	{
		if (idx < 0 || idx >= _size)
			throw Array::OutOfBoundException();
		return _arr[idx];
	}
	class OutOfBoundException : public std::exception
	{
	public:
		const char* what(void) const throw()
		{
			return "Out of Bounds";
		}
	};
};

#endif
