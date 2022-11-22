/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:14:31 by apommier          #+#    #+#             */
/*   Updated: 2022/11/22 08:23:53 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>
# include "./iterator_traits.hpp"

namespace ft 
{
	template<typename Iter>
	class reverse_iterator
	{
		public:

		typedef	Iter													iterator_type;
		typedef	typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef	typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef	typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef	typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef	typename ft::iterator_traits<Iter>::reference			reference;

		private:	
			
			iterator_type	_Ite;

		public:
		
		//---------------------------------------
		//--------CONSTRUCTOR DESTRUCTOR---------
		//---------------------------------------
		
		reverse_iterator() : _Ite() {}
		explicit reverse_iterator (iterator_type it) { _Ite = iterator_type(it); }
		
		//reverse_iterator(const reverse_iterator<It> &rev_it) : _Ite(rev_it.base()) {}

		template<typename It>
		reverse_iterator(const reverse_iterator<It> &rev_it)
		{
			*this = rev_it;
		}
		
		virtual ~reverse_iterator(){}
		// reverse_iterator(const reverse_iterator<It> &rev_it)
		// {
		// 	_Ite = It(rev_it.base());
		// }
		// operator reverse_iterator<Iter>() const 
		// {
		// 	return (reverse_iterator< Iter const>(_Ite));
		// }
		
		template<typename It>
		reverse_iterator operator=(reverse_iterator<It> const &cpy)
		{
			_Ite = cpy.base(); 
			return (*this);
		}
		


		//---------------------------------------
		//-------------COMPARAISON---------------
		//---------------------------------------
		
		// bool operator== (reverse_iterator const &rhs) const { return (_Ite == rhs.base()); }
		// bool operator!= (reverse_iterator const &rhs) const { return (_Ite != rhs.base()); }
		// bool operator<  (reverse_iterator const &rhs) const { return (_Ite > rhs.base()); }
		// bool operator<= (reverse_iterator const &rhs) const { return (_Ite >= rhs.base()); }
		// bool operator>  (reverse_iterator const &rhs) const { return (_Ite < rhs.base()); }
		// bool operator>= (reverse_iterator const &rhs) const { return (_Ite <= rhs.base()); }

		//---------------------------------------
		//-------------INCREMENTERS--------------
		//---------------------------------------

		reverse_iterator& operator++()
		{
			--_Ite;
			return (*this);
		}
		
		reverse_iterator  operator++(int) 
		{
			reverse_iterator tmp = *this;
			--_Ite;
			return (tmp);
		}
		
		reverse_iterator& operator--() 
		{
			++_Ite;
			return (*this);
		}
		
		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp = *this;
			++_Ite;
			return (tmp);
		}

		//---------------------------------------
		//----------------ADRESS-----------------
		//---------------------------------------

		reference operator *() { return (*_Ite); }
		const reference operator *() const { return (*_Ite); }
		pointer operator ->() { return (_Ite.getPointer()); }
		const pointer operator ->() const { return (_Ite.getPointer()); }
		reference operator [](difference_type nbr) const { return (*(_Ite + nbr)); }

		//---------------------------------------
		//--------------OPERATION----------------
		//---------------------------------------

		// reverse_iterator operator+ (difference_type n) const { return reverse_iterator<iterator_type>(_Ite - n); }
		// reverse_iterator& operator+= (difference_type n) { return reverse_iterator<iterator_type>(_Ite -= n); }
		// reverse_iterator operator- (difference_type n) const { return reverse_iterator<iterator_type>(_Ite + n); }
		// reverse_iterator& operator-= (difference_type n) { return reverse_iterator<iterator_type>(_Ite += n); }

		reverse_iterator operator+ (difference_type n) const { return reverse_iterator(_Ite - n); }
		
		friend reverse_iterator operator +(difference_type lhs, reverse_iterator const& rhs) { return (rhs + lhs); } // n + a

		reverse_iterator& operator+= (difference_type n)
		{
			_Ite -= n;
			return (*this);
		}
		
		reverse_iterator operator- (difference_type n) const { return reverse_iterator(_Ite + n); }
		
		difference_type operator- (reverse_iterator const &lhs) const { return (_Ite - lhs._Ite); }

		reverse_iterator& operator-= (difference_type n)
		{
			//std::cout << "its me\n";
			_Ite += n;
			return (*this);
		}


		// template <class Iterator>
		// reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
		// {
			
		// }

		// template <class Iterator>
		// typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		// {
			
		// }

		//---------------------------------
		//--------------GET----------------
		//---------------------------------

		iterator_type base() const { return _Ite; }
	};

		template<class Ite1, class Ite2>
		bool operator== (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs) { return (lhs.base() == rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator!= (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs) { return (lhs.base() != rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator<  (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs) { return (lhs.base() > rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator<= (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs) { return (lhs.base() >= rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator>  (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs) { return (lhs.base() < rhs.base()); }
		
		template<class Ite1, class Ite2>
		bool operator>= (const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs) { return (lhs.base() <= rhs.base()); }


}