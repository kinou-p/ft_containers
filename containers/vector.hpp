/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:46:32 by apommier          #+#    #+#             */
/*   Updated: 2022/11/29 15:46:33 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "./iterators/random_access_iterator.hpp"
# include "./iterators/enable_if.hpp"
# include "./iterators/is_integral.hpp"
# include "./iterators/equal.hpp"
# include "./iterators/reverse_iterator.hpp"

# include <cstddef>
# include <limits>
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
	typedef ft::random_access_iterator< value_type const>	const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef std::ptrdiff_t									difference_type;
	typedef std::size_t										size_type;	 
	
	//-----------------------------
	//-----PRIVATE MEMBER TYPE-----
	//-----------------------------
	private:

		pointer					_tab;
		size_type				_size;
		size_type				_capacity;

		allocator_type			_alloc;

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
	
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc) //fill constructor
	{
		if (n)
			_tab = _alloc.allocate(n);
		else
			_tab = 0;
		_size = n;
		_capacity = n;
		for (size_type i = 0; i < n ; i++)
			_alloc.construct(_tab + i, val);
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _alloc(alloc)  //range constructor
	{
		_tab = 0;
		difference_type	diff = 0;
		InputIterator tmp = first;
		while(tmp != last)
		{
			diff++;
			tmp++;
		}
		_size = diff;
		_capacity = diff;
		if (_capacity)
			_tab = _alloc.allocate(_capacity);
		else
			_tab = 0;
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(_tab + i, *first++);
	}

	vector (const vector& x)//copy constructor
	{
		_tab = 0;
		_size = 0;
		_capacity = 0;	
		*this = x;
	}

	~vector()
	{
		if (_capacity)
		{
			this->destroy_tab();
			_alloc.deallocate(_tab, _capacity);
			_capacity = 0;
		}
	}
	
	vector& operator= (const vector& x)//assignation operator
	{
		if (_capacity)
		{
			this->destroy_tab();
			_alloc.deallocate(_tab, _capacity);
			_capacity = 0;
		}
		_alloc = x._alloc;
		_size = x._size;
		_capacity = x._size;
		if (_capacity)
			_tab = _alloc.allocate(_size);
		else
			_tab = 0;
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(_tab + i, x._tab[i]); 
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
			return (iterator(_tab));
		}
		
		const_iterator begin() const
		{
			return const_iterator(_tab);
		}

		iterator end()
		{
			return iterator(_tab + _size);
		}

		const_iterator end() const
		{
			return const_iterator(_tab + _size);
		}
		
		reverse_iterator rbegin()
		{
			return reverse_iterator(this->end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(this->end());
		}
		
		reverse_iterator rend()
		{
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->begin());
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
					_size--;
					_alloc.destroy(_tab + _size);
				}
			}
			else if (n > _size)
			{
				if (n > _capacity)
				{
					if (n == _capacity + 1 || n > _capacity * 2)
						this->reserve(n);
					else
						this->reserve(_capacity * 2);
				}
				while (n > _size)
				{
					_alloc.construct(_tab + _size, val);
					_size++;
				}
				
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
				tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(tmp + i, *(_tab + i));
				if (_capacity)
				{
					this->destroy_tab();
					_alloc.deallocate(_tab, _capacity);
				}
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
			if (n >= _size)
				throw (std::out_of_range("ft::vector::at"));
			return (*(_tab + n));
		}
		
		const_reference at (size_type n) const
		{
			if (n >= _size)
				throw (std::out_of_range("ft::vector::at"));
			return (*(_tab + n));
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
			return (*(_tab + _size - 1));
		}
		
		const_reference back() const
		{
			return (*(_tab + _size - 1));
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

		template <class _InputIterator>
		void assign(typename ft::enable_if<!std::numeric_limits<_InputIterator>::is_integer, _InputIterator>::type first, _InputIterator last)
		{
			size_type	diff = 0;
			
			for (_InputIterator tmp = first; tmp != last; tmp++)
				diff++;
			size_type i = 0;
			if (_capacity < diff)
				i = 1;
			this->clear();
			if (i)
				resize(diff);
			for (size_type tmp = 0; tmp != diff; tmp++)
				_alloc.construct(_tab + tmp, *first++);
			_size = diff;
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
		
		void push_back (const_reference val)
		{
			if (!_capacity)
				this->reserve(1);
			else if (_size == _capacity)
				this->reserve(_size * 2);
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
			difference_type index = position - begin();

			insert(position, 1, val);
			return (iterator(begin() + index));
		}
		
		void insert (iterator position, size_type n, const value_type& val) //fill
		{
			difference_type const pos_diff = position - begin();
			difference_type const old_end_diff = end() - begin();
			iterator old_end;
			iterator new_end;
			
			resize(this->_size + n);
			new_end = end();
			position = begin() + pos_diff;
			old_end = begin() + old_end_diff;
			while (old_end != position)
				*--new_end = *--old_end;
			while (n-- > 0)
				*position++ = val;
		}
		
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
				size_type n = 0;
				for (InputIterator tmp = first; tmp != last; tmp++) {
					n++;
				}
				difference_type const pos_diff = position - begin();
				difference_type const old_end_diff = end() - begin();
				iterator old_end;
				iterator new_end;

				resize(_size + n);
				new_end = end();
				position = begin() + pos_diff;
				old_end = begin() + old_end_diff;
				while (old_end != position)
					*--new_end = *--old_end;
				while (first != last)
					*position++ = *first++;
		}

		iterator erase (iterator position)
		{
			_alloc.destroy(&(*position));
			for (size_type i = 0; _tab + _size - 1 > _tab + (position - _tab + i); i++)
			{
				_alloc.construct(&(*(position + i)), *(position + i + 1));
				_alloc.destroy(&(*(position + i + 1)));
			}
			_size--;
			return (position);
		}

		iterator erase (iterator first, iterator last)
		{

			iterator temp(first);

			while (temp != last)
			{
				erase(first);
				temp++;
			}
			return (first);
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
	
		//-------------------------
		//-------Comparaison-------
		//-------------------------

		template <class Temp, class Alloc>
		friend bool operator== (const vector<Temp,Alloc>& lhs, const vector<Temp,Alloc>& rhs);
		template <class Temp, class Alloc>
		friend bool operator!= (const vector<Temp,Alloc>& lhs, const vector<Temp,Alloc>& rhs);
		template <class Temp, class Alloc>
		friend bool operator<  (const vector<Temp,Alloc>& lhs, const vector<Temp,Alloc>& rhs); 
		template <class Temp, class Alloc>
		friend bool operator<= (const vector<Temp,Alloc>& lhs, const vector<Temp,Alloc>& rhs);
		template <class Temp, class Alloc>
		friend bool operator>  (const vector<Temp,Alloc>& lhs, const vector<Temp,Alloc>& rhs);
		template <class Temp, class Alloc>
		friend bool operator>= (const vector<Temp,Alloc>& lhs, const vector<Temp,Alloc>& rhs);

		private:

		void destroy_tab()
		{
			size_type i = 0;

			while(i < _size)
			{
				_alloc.destroy(_tab + i);
				i++;
			}
		}
};

	//---------------------------------------------
	//---------OPERATOR OVERLOAD FUNCTION----------
	//---------------------------------------------
	
	template <class T, class Alloc>  
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs._size != rhs._size)
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template <class T, class Alloc>  
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <class T, class Alloc>  
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		int i = 0;
		while (lhs._size - i && rhs._size - i && lhs._tab[i] == rhs._tab[i])
			i++;
		if (!(lhs._size - i) && rhs._size - i)
			return true;
		if (!(rhs._size - i) && lhs._size - i)
			return false;
		if (!(lhs._size - i) && !(rhs._size - i))
			return false;
		return (lhs._tab[i] < rhs._tab[i]);
	}
	
	template <class T, class Alloc>  
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	
	template <class T, class Alloc>  
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T, class Alloc>  
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	
	
}
#endif