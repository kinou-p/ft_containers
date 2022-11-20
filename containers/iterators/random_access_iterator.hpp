/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:14:35 by apommier          #+#    #+#             */
/*   Updated: 2022/11/19 12:42:38 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>

namespace ft 
{
	template<typename T>
	class random_access_iterator
	{
		public:

			typedef T				value_type;
			typedef	std::ptrdiff_t	difference_type;	
			typedef	T*				pointer;
			typedef	T&				reference;

		private:	
			
			pointer _ptr;

		public:
		
		//---------------------------------------
		//--------CONSTRUCTOR DESTRUCTOR---------
		//---------------------------------------
		
		random_access_iterator(){ _ptr = NULL;}
		random_access_iterator(pointer ptr){ _ptr = ptr;}
		random_access_iterator(random_access_iterator const &cpy) {*this = cpy;}

		~random_access_iterator(){}
		
		random_access_iterator &operator=(random_access_iterator const &cpy)
		{
			_ptr = cpy._ptr;
			return (*this);
		}

		operator random_access_iterator<value_type const>() const
		{
			return (random_access_iterator<value_type const>(_ptr));
		}
		// random_access_iterator &operator=(pointer &ptr)
		// {
		// 	_ptr = ptr;
		// 	return (*this);
		// }
		
		//---------------------------------------
		//-------------COMPARAISON---------------
		//---------------------------------------

		friend bool operator ==(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr == b._ptr); }
		friend bool operator !=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr != b._ptr); }
		friend bool operator <(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr < b._ptr); }
		friend bool operator >(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr > b._ptr); }
		friend bool operator <=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr <= b._ptr); }
		friend bool operator >=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr >= b._ptr); }

		//---------------------------------------
		//-------------INCREMENTERS--------------
		//---------------------------------------
		
		random_access_iterator &operator ++()
		{
			_ptr++; 
			return (*this);
		}
		
		random_access_iterator operator ++(int)
		{
			random_access_iterator tmp(*this);
			++(*this);
			return (tmp);
		}

		random_access_iterator &operator --()
		{
			_ptr--;
			return (*this);
		}
		
		random_access_iterator operator --(int)
		{
			random_access_iterator tmp(*this);
			--(*this);
			return (tmp);			
		}

		//---------------------------------------
		//----------------ADRESS-----------------
		//---------------------------------------

		reference operator *() { return (*_ptr); }
		reference operator *() const { return (*_ptr); }
		pointer operator ->() { return (_ptr); }
		pointer operator ->() const { return (_ptr); }
		// reference operator [](difference_type nbr) { return (*(_ptr + nbr)); } const
		reference operator [](difference_type nbr) const { return (*(_ptr + nbr)); }

		//---------------------------------------
		//--------------OPERATION----------------
		//---------------------------------------
		
		// addition | soustraction
		random_access_iterator operator +(difference_type const nbr) const { return (random_access_iterator(_ptr + nbr)); } // a + n
		friend random_access_iterator operator +(int const lhs, random_access_iterator const& rhs) { return (rhs + lhs); } // n + a
		random_access_iterator operator -(difference_type nbr) { return random_access_iterator(_ptr - nbr); } // a - n
		difference_type operator -(random_access_iterator const &rhs) const { return (_ptr - rhs._ptr) ; } // a - b
		//friend difference_type &operator -(random_access_iterator const& lhs, random_access_iterator const& rhs) { return ((difference_type)(lhs._ptr - rhs._ptr)); } // a - b
		//random_access_iterator operator -(const random_access_iterator &b) { return random_access_iterator(_ptr + b); } // a - b 2?

		random_access_iterator &operator +=(difference_type nbr)
		{
			_ptr += nbr;
			return (*this);
		}
		
		random_access_iterator &operator -=(difference_type nbr)
		{
			_ptr -= nbr;
			return (*this);
		}
		
		//---------------------------------
		//--------------GET----------------
		//---------------------------------

		pointer getPointer()
		{
			return (_ptr);
		}
	};

	
}

#endif