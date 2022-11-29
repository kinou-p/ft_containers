/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:14:35 by apommier          #+#    #+#             */
/*   Updated: 2022/11/29 17:27:54 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>
# include "./iterator_traits.hpp"

namespace ft 
{
	template<typename T>
	class random_access_iterator
	{
		public:

			typedef T							value_type;
			typedef	std::ptrdiff_t				difference_type;	
			typedef	T*							pointer;
			typedef	T&							reference;
			typedef random_access_iterator		iterator_category;

		private:	
			
			pointer _ptr;

		public:
		
		//---------------------------------------
		//--------CONSTRUCTOR DESTRUCTOR---------
		//---------------------------------------
		
		random_access_iterator(){ _ptr = NULL;}
		random_access_iterator(pointer ptr){ _ptr = ptr;}
		random_access_iterator(const random_access_iterator &cpy) {*this = cpy;}

		~random_access_iterator(){}

		operator random_access_iterator<const value_type>() const
		{
		 	return (random_access_iterator<const value_type>(_ptr));
		}
		
		random_access_iterator &operator=(random_access_iterator const &rhs)
		{
			if (this != &rhs) 
			{
				this->_ptr = rhs._ptr;
			}
			return (*this);
		}

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
		reference operator [](difference_type nbr) const { return (*(_ptr + nbr)); }

		//---------------------------------------
		//--------------OPERATION----------------
		//---------------------------------------
		
		// addition | soustraction
		random_access_iterator operator +(difference_type const nbr) const { return (random_access_iterator(_ptr + nbr)); } // a + n
		friend random_access_iterator operator +(int const lhs, random_access_iterator const& rhs) { return (rhs + lhs); } // n + a
		random_access_iterator operator -(difference_type nbr) const { return random_access_iterator(_ptr - nbr); } // a - n
		difference_type operator -(random_access_iterator const &rhs) const { return (_ptr - rhs._ptr) ; } // a - b

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

		//---------------------------------------
		//-------------COMPARAISON---------------
		//---------------------------------------

		friend bool operator ==(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr == b._ptr); }
		friend bool operator !=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr != b._ptr); }
		friend bool operator <(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr < b._ptr); }
		friend bool operator >(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr > b._ptr); }
		friend bool operator <=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr <= b._ptr); }
		friend bool operator >=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr >= b._ptr); }
	};
}

#endif