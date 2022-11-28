/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:14:35 by apommier          #+#    #+#             */
/*   Updated: 2022/11/28 13:35:24 by apommier         ###   ########.fr       */
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

			// typedef	typename ft::iterator_traits<T>::iterator_category	iterator_category;
			// typedef	typename ft::iterator_traits<T>::value_type			value_type;
			// typedef	typename ft::iterator_traits<T>::difference_type	difference_type;
			// typedef	typename ft::iterator_traits<T>::pointer			pointer;
			// typedef	typename ft::iterator_traits<T>::reference			reference;

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
		
		// random_access_iterator &operator=(const random_access_iterator  &cpy)
		// {
		// 	_ptr = cpy._ptr;
		// 	return (*this);
		// }


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


		// random_access_iterator &operator=(pointer &ptr)
		// {
		// 	_ptr = ptr;
		// 	return (*this);
		// }
		


		//---------------------------------------
		//-------------INCREMENTERS--------------
		//---------------------------------------
		
		random_access_iterator &operator ++()
		{
			//std::cout << "operandom ++\n";
			_ptr++; 
			return (*this);
		}
		
		random_access_iterator operator ++(int)
		{
			//std::cout << "operandom 1 ++\n";
			random_access_iterator tmp(*this);
			++(*this);
			return (tmp);
		}

		random_access_iterator &operator --()
		{
			//std::cout << "operandom --\n";
			_ptr--;
			return (*this);
		}
		
		random_access_iterator operator --(int)
		{
			//std::cout << "operandom 1 --\n";
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
		random_access_iterator operator -(difference_type nbr) const { return random_access_iterator(_ptr - nbr); } // a - n
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

		//---------------------------------------
		//-------------COMPARAISON---------------
		//---------------------------------------

		// bool operator ==(const random_access_iterator &b) { return (this->_ptr == b._ptr); }
		// bool operator !=(const random_access_iterator &b) { return (this->_ptr != b._ptr); }
		// bool operator <(const random_access_iterator &b) { return (this->_ptr < b._ptr); }
		// bool operator >(const random_access_iterator &b) { return (this->_ptr > b._ptr); }
		// bool operator <=(const random_access_iterator &b) { return (this->_ptr <= b._ptr); }
		// bool operator >=(const random_access_iterator &b) { return (this->_ptr >= b._ptr); }
		friend bool operator ==(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr == b._ptr); }
		friend bool operator !=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr != b._ptr); }
		friend bool operator <(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr < b._ptr); }
		friend bool operator >(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr > b._ptr); }
		friend bool operator <=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr <= b._ptr); }
		friend bool operator >=(random_access_iterator const& a, random_access_iterator const& b) { return (a._ptr >= b._ptr); }
	};

	//---------------------------------------
	//-------------COMPARAISON---------------
	//---------------------------------------
	
	// template<typename _Ite>
	// bool operator ==(const random_access_iterator<_Ite> &a, const random_access_iterator<_Ite> &b) { return (a._ptr == b._ptr); }
	// template<typename _Ite>
	// bool operator !=(const random_access_iterator<_Ite> &a, const random_access_iterator<_Ite> &b) { return (a._ptr != b._ptr); }
	// template<typename _Ite>
	// bool operator <(const random_access_iterator<_Ite> &a, const random_access_iterator<_Ite> &b) { return (a._ptr < b._ptr); }
	// template<typename _Ite>
	// bool operator >(const random_access_iterator<_Ite> &a, const random_access_iterator<_Ite> &b) { return (a._ptr > b._ptr); }
	// template<typename _Ite>
	// bool operator <=(const random_access_iterator<_Ite> &a, const random_access_iterator<_Ite> &b) { return (a._ptr <= b._ptr); }
	// template<typename _Ite>
	// bool operator >=(const random_access_iterator<_Ite> &a, const random_access_iterator<_Ite> &b) { return (a._ptr >= b._ptr); }
}

	// template <typename U>
	// ft::random_access_iterator<U> operator +(std::ptrdiff_t const nbr, ft::random_access_iterator<U> const& rhs)
	// {
	// 	return (rhs + nbr);
	// } // n + a
	// template<class _Iterator>
	// ft::random_access_iterator<_Iterator> operator+(typename ft::random_access_iterator<_Iterator>::difference_type n, ft::random_access_iterator<_Iterator> const &lhs) 
	// {
	// 	return (lhs + n);
	// }

#endif