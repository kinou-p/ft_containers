/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:46:32 by apommier          #+#    #+#             */
/*   Updated: 2022/10/28 17:58:43 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{

template< class T, class Allocator = std::allocator<T> >	
class vector
{
	public:
	//-----------------------------
	//---------MEMBER TYPE---------
	//-----------------------------
	typedef T										value_type;
	typedef Allocator 								allocator_type;
	typedef value_type& 							reference;
	typedef const value_type&						const_reference;
	typedef typename Allocator::pointer				pointer;
	typedef typename Allocator::const_pointer		const_pointer;
	typedef value_type*	iterator;
	typedef value_type*	const_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef std::ptrdiff_t							difference_type;
	typedef std::size_t								size_type;
	 
	//---------------------------------------
	//---------COPLIEN FORM FUNCTION---------
	//---------------------------------------
	explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc) //default constructor
	{
		_tab = 0;
		_size = 0;
		_capacity = 0;
		_start = 0;
		_end = 0;
		_alloc = alloc;
		//_end_capacity = 0;
	}
	
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc) //fill constructor
	{
		_tab = 0;
		_size = 0;
		_capacity = 0;
		_start = 0;
		_end = 0;
		//_end_capacity = 0;

		_alloc = alloc;
		_start = _alloc.allocate(n);
		_end = _start + n;
		_size = n;
		_capacity = n;
		while (n--)
			alloc.construct(val, _end - n);
	}
	
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) //range constructor
	{

	}
	
	vector (const vector& x)//copy constructor
	{
		
	}
	
	~vector()
	{

	}
	
	vector& operator= (const vector& x)//assignation operator
	{

	}
	
	//----------------------------------
	//---------MEMBER FUNCTION----------
	//----------------------------------
	
		//-------------------------
		//--------Iterators--------
		//-------------------------
		iterator begin()
		{
			return (_start);
		}
		
		iterator end()
		{
			return (_end);
		}
		
		reverse_iterator rbegin()
		{
			return (_end);
		}
		
		reverse_iterator rend()
		{
			return (_start);
		}
		
		//------------------------
		//--------Capacity--------
		//------------------------
		size_type size() const
		{
			return (_end - _start);
		}
		
		size_type max_size() const
		{
			return (_alloc.max_size());
		}
		
		void resize (size_type n, value_type val = value_type()) //Resizes the container so that it contains n elements.
		{
			if (n > this->max_size())
				throw (std::length_error("vector::resize"));
			else if (n < this->size())
			{
				while (n > this->size())
				{
					_end--;
					_alloc.destroy(_end);
				}
			}
			//else // n > size
				//insert()
		}
		
		size_type capacity() const
		{
			return (_capacity);
		}
		
		bool empty() const
		{
			if (_end == _start)
				return (1);
			return(0);
		}
		
		void reserve (size_type n)
		{

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
			return (*_start);
		}
		
		const_reference front() const
		{
			return (*_start);
		}
		
		reference back()
		{
			return (*_end);
		}
		
		const_reference back() const
		{
			return (*_end);
		}
		
		value_type* data()
		{
			return (_start);
		}
		
		const value_type* data() const
		{
			return (_start);
		}
		
		//-------------------------
		//--------Modifiers--------
		//-------------------------
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) //range
		{

		}
		
		void assign (size_type n, const value_type& val) //fill
		{
			
			this->clear();
			if (n > this->max_size())
				throw (std::length_error("vector::resize"));
			else if (n < this->size())
			{
				while (n > this->size())
				{
					_end--;
					_alloc.destroy(_end);
				}
			}
			//else // n > size
				//insert()
		}
		
		void push_back (const value_type& val)
		{
			if (!this->max_size() - _size)
				;
				//throw or alloc
			else
			{
				_alloc.construct(val, end);
				_size++;
				_end++;
			}
		}
		
		void pop_back()
		{
			//if (!_size)
			//	;
				//throw std::;
			_alloc.destroy(_end - 1);
			_end--;
			_size--;
		}
		
		iterator insert (iterator position, const value_type& val) //single element
		{
			
		}
		
		void insert (iterator position, size_type n, const value_type& val) //fill
		{

		}
		
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) //range
		{

		}
		
		iterator erase (iterator position)
		{
			
		}

		iterator erase (iterator first, iterator last)
		{
			
		}
		
		void swap (vector& x)
		{
				
		}
		
		void clear()
		{
			int i = 0;
			
			while (_start != _end)
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

	
	private:
		
		value_type		*_tab;
		size_type		_size;
		size_type		_capacity;
		
		allocator_type	_alloc;
		pointer			_end;
		pointer			_start;
		//pointer			_end_capacity;
};
	
}
#endif