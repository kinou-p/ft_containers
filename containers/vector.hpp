/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:46:32 by apommier          #+#    #+#             */
/*   Updated: 2022/11/17 06:53:12 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "./iterators/random_access_iterator.hpp"

# include <cstddef>
# include <memory>
# include <stdexcept>


namespace ft
{

template< class T, class Allocator = std::allocator<T> >	
class vector
{
	public:
	//-----------------------------
	//---------MEMBER TYPE---------
	//-----------------------------
	typedef T												value_type;
	typedef Allocator 										allocator_type;
	typedef value_type& 									reference;
	typedef const value_type&								const_reference;
	typedef T*												pointer;
	typedef const T*										const_pointer;
	typedef ft::random_access_iterator<value_type>			iterator;
	typedef const ft::random_access_iterator<value_type>	const_iterator;
	typedef std::reverse_iterator<iterator>					reverse_iterator;
	typedef std::reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef std::ptrdiff_t									difference_type;
	typedef std::size_t										size_type;
	 
	
	//-----------------------------
	//-----PRIVATE MEMBER TYPE-----
	//-----------------------------
	private:

		value_type				*_tab;
		size_type				_size;
		size_type				_capacity;

		allocator_type			_alloc;
		//ft::random_access_iterator<value_type>	_end;
		//ft::random_access_iterator<value_type>	_start;
		
		//pointer			_end_capacity;

	public:
	
	//---------------------------------------
	//---------COPLIEN FORM FUNCTION---------
	//---------------------------------------
	explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc) //default constructor
	{
		_tab = 0;
		_size = 0;
		_capacity = 0;	
		_alloc = alloc;
	}
	
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc) //fill constructor
	{
		_tab = 0;
		_size = 0;
		_capacity = 0;

		_alloc = alloc;
		_tab = _alloc.allocate(n);
		_size = n;
		_capacity = n;
		while (n--)
			_alloc.construct(_tab + n, val);
	}
	
	vector (const vector& x)//copy constructor
	{
		*this = x;
	}
	
	~vector()
	{
		if (_tab && _capacity)
			_alloc.deallocate(_tab, _capacity);
	}
	
	vector& operator= (const vector& x)//assignation operator
	{
			_tab = x._tab;
			_size = x._size;
			_capacity = x._capacity;
			_alloc = x._alloc;  
			return (*this);
	}
	
	//----------------------------------
	//---------MEMBER FUNCTION----------
	//----------------------------------
	
		//-------------------------
		//--------Iterators--------
		//-------------------------
		iterator begin()
		{
			return (_tab);
		}
		
		iterator end()
		{
			return (_tab + _size);
		}
		
		reverse_iterator rbegin()
		{
			return (_tab + _size);
		}
		
		reverse_iterator rend()
		{
			return (_tab);
		}
		
		//------------------------
		//--------Capacity--------
		//------------------------
		size_type size() const
		{
			return (_size);
		}
		
		size_type max_size() const
		{
			return (_alloc.max_size());
		}
		
		void resize (size_type n, value_type val = value_type()) //Resizes the container so that it contains n elements.
		{
			
			if (n < _size) 
			{
				while (n < _size)
				{
					//_end--;
					_size--;
					_alloc.destroy(_tab + _size);
				}
			}
			else if (n > _size)
			{
				this->reserve(n);
				while (n > _size)
				{
					_alloc.construct(_tab + _size, val);
					//_end++;
				}
				_size = n;
			}
		}
		
		size_type capacity() const
		{
			return (_capacity);
		}
		
		bool empty() const
		{
			if (!_size)
				return (1);
			return(0);
		}
		
		void reserve (size_type n)
		{
			if (n > this->max_size())
				throw (std::length_error("ft::vector::reserve"));
			else if (n > _capacity)
			{
				value_type *tmp;
				tmp = _alloc.allocate(n, 0);
				for (int i = 0; _tab + i != _tab + _size; i++)
					*(tmp + i) = *(_tab + i);
				_alloc.deallocate(_tab, _capacity);
				_tab = tmp;
				_capacity = n;
			}
		}
		
		//------------------------------
		//--------Element access--------
		//------------------------------
		reference operator[] (size_type n)
		{
			return (_tab[n]);
		}
		
		const_reference operator[] (size_type n) const
		{
			return (_tab[n]);
		}

		reference at (size_type n)
		{
			//exception
			return (_tab[n]);
		}
		
		const_reference at (size_type n) const
		{
			//exception
			return (_tab[n]);
		}
		
		reference front()
		{
			return (*_tab);
		}
		
		const_reference front() const
		{
			return (*_tab);
		}
		
		reference back()
		{
			return (*(_tab + _size));
		}
		
		const_reference back() const
		{
			return (*(_tab + _size));
		}
		
		value_type* data()
		{
			return (_tab);
		}
		
		const value_type* data() const
		{
			return (_tab);
		}
		
		//-------------------------
		//--------Modifiers--------
		//-------------------------
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) //range
		{
			this->clear();
			while (first < last)
			{
				push_back(*first);
				first++;
			}
		}
		
		void assign (size_type n, const value_type& val) //fill
		{
			if (n > this->max_size())
				throw (std::length_error("vector::resize"));
			this->clear();
			this->resize(n);
			while (n--)
				_alloc.construct(_tab + n, val);
		}
		
		void push_back (const value_type& val)
		{
			if (!_capacity)
				this->reserve(1);
			else if (_size == _capacity)
				this->reserve(_size);
			_alloc.construct(_tab + _size, val);
			_size++;
		}
		
		void pop_back()
		{
			if (_size)
			{
				_alloc.destroy(_tab + _size - 1);
				_size--;
			}
		}
		
		iterator insert (iterator position, const value_type& val) //single element
		{
			this->insert(position, 1, val);
		}
		
		void insert (iterator position, size_type n, const value_type& val) //fill
		{
			int j = 0;
			int i; 
			value_type *tmp;
			
			if (_size + n > this->max_size())
				throw (std::length_error("vector::resize"));
			tmp = _alloc.allocate(_size + n);
			for (i = 0; i < position; i++)
				tmp[i] = _tab[i];
			while (n - j)
			{
				tmp[i + j] = val;
				j++;
			}
			while (_size - i)
				tmp[i + j] = _tab[i];
			this->clear();
			_tab = tmp;
			_size += n;
			_capacity = _size;
		}
		
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) //range
		{
			int j = 0;
			int i;
			value_type *tmp;
			
			if (_size + (last - first) > this->max_size())
				throw (std::length_error("vector::resize"));
			tmp = _alloc.allocate(_size + (last - first));
			for (i = 0; i < position; i++)
				tmp[i] = _tab[i];
			while (first + j != last)
			{
				tmp[i + j] = *(first + j);
				j++;
			}
			while (_size - i)
				tmp[i + j] = _tab[i];
			this->clear();
			_tab = tmp;
			_size += (last - first);
			_capacity = _size;
		}

		iterator erase (iterator position)
		{
			iterator ret = position;
			_alloc.destroy(position);
			while (_tab + _size - 1 > position + _tab)
			{
				*position = *(position + 1);
				position++;
				_alloc.destroy(position);
			}
			_size--;
			return (ret + 1);
		}

		iterator erase (iterator first, iterator last)
		{
			difference_type lenght = last - first;
			
			for (int i = 0; lenght - i; i++)
				_alloc.destroy(first + i);
			while (_tab + _size - 1 != _tab + lenght)
			{
				*first = *(first + lenght);
				first++;
				_alloc.destroy(first + lenght);
			}	
			return (last + 1);
		}
		
		void swap (vector& x)
		{
			value_type *tab_tmp = _tab;
			size_type	size_tmp = _size;
			size_type	capacity_tmp = _capacity;
			allocator_type	alloc_tmp = _alloc;

			_tab = x._tab;
			_size = x._size;
			_capacity = x._capacity;
			_alloc = x._alloc;

			x._tab = tab_tmp;
			x._size = size_tmp;
			x._capacity = capacity_tmp;
			x._alloc = alloc_tmp;
		}

		void clear()
		{
			while (_size)
				this->pop_back();
		}
		
		//-------------------------
		//--------Allocator--------
		//-------------------------
		allocator_type get_alloc() const
		{
			return (_alloc);
		}
	
	//---------------------------------------------
	//---------OPERATOR OVERLOAD FUNCTION----------
	//---------------------------------------------

	// template <class T, class Alloc>
	// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	
	// }
	
	// template <class T, class Alloc>
	// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	
	// }
	
	// template <class T, class Alloc>
	// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	
	// }
	
	// template <class T, class Alloc>
	// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	
	// }
	
	// template <class T, class Alloc>
	// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	
	// }
	
	// template <class T, class Alloc>
	// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	// {
	
	// }
};
	
}
#endif